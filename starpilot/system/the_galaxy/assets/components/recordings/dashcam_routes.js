import { html, reactive } from "/assets/vendor/arrow-core.js"
import { escapeHtml, isGalaxyTunnel } from "/assets/js/utils.js"
import { Modal } from "/assets/components/modal.js"
import {
  buildRouteView,
  cameraVideoUrl,
  formatApproxDuration,
  getSegmentStatus,
  groupRoutesByDate,
  MAX_RENDERED_ROUTES,
  normalizeRoute,
} from "/assets/components/recordings/dashcam_routes_helpers.js"

const state = reactive({
  loading: true,
  error: null,
  routes: [],
  selectedRoute: null,
  searchQuery: "",
  sortOrder: "newest",
  showPreservedOnly: false,
  progress: 0,
  total: 0,
  showDeleteAllModal: false,
  isDeletingAll: false,
})

let routesAbortController = null
let routesRequestToken = 0
let seenRouteNames = new Set()
let overlay = null

function routeLabel(route) {
  return route.displayName || route.displayDate || route.name
}

function mergeRoutes(rawRoutes) {
  if (!Array.isArray(rawRoutes) || rawRoutes.length === 0) return
  const additions = []
  for (const rawRoute of rawRoutes) {
    const name = String(rawRoute?.name || "")
    if (!name || seenRouteNames.has(name)) continue
    seenRouteNames.add(name)
    additions.push(normalizeRoute(rawRoute))
  }
  // Worker completion order is irrelevant: buildRouteView sorts the list at render time.
  if (additions.length) state.routes = [...state.routes, ...additions]
}

async function fetchRoutes() {
  const requestToken = ++routesRequestToken
  routesAbortController?.abort()
  const controller = new AbortController()
  routesAbortController = controller

  try {
    const response = await fetch("/api/routes", { signal: controller.signal })
    if (!response.ok || !response.body) throw new Error(`Route request failed (${response.status})`)

    const reader = response.body.getReader()
    const decoder = new TextDecoder()
    let buffer = ""
    while (true) {
      const { value, done } = await reader.read()
      if (done) break
      if (requestToken !== routesRequestToken) return

      buffer += decoder.decode(value, { stream: true })
      const events = buffer.split(/\r?\n\r?\n/)
      buffer = events.pop() || ""
      for (const event of events) {
        const dataLines = event.split(/\r?\n/).filter(line => line.startsWith("data:"))
        if (!dataLines.length) continue
        try {
          const payload = JSON.parse(dataLines.map(line => line.slice(5).trimStart()).join("\n"))
          if (Number.isFinite(payload.progress)) state.progress = payload.progress
          if (Number.isFinite(payload.total)) state.total = payload.total
          mergeRoutes(payload.routes)
        } catch (error) {
          console.error("Failed to parse route stream event:", error)
        }
      }
    }
  } catch (error) {
    if (error?.name !== "AbortError") state.error = "Couldn't load routes. Try refreshing."
  } finally {
    if (requestToken === routesRequestToken) {
      state.loading = false
      if (routesAbortController === controller) routesAbortController = null
    }
  }
}

function refresh() {
  state.loading = true
  state.error = null
  state.routes = []
  state.progress = 0
  state.total = 0
  seenRouteNames = new Set()
  return fetchRoutes()
}

if (!isGalaxyTunnel()) refresh()

function openDialog(htmlString) {
  const dialog = document.createElement("div")
  dialog.className = "dialog-overlay"
  dialog.innerHTML = htmlString
  document.body.appendChild(dialog)
  return dialog
}

function closeDialog(dialog) {
  dialog?.remove()
}

function replaceRoute(updatedRoute) {
  state.routes = state.routes.map(route => route.name === updatedRoute.name ? updatedRoute : route)
  if (state.selectedRoute?.name === updatedRoute.name) state.selectedRoute = updatedRoute
}

async function deleteRoute(route) {
  const dialog = openDialog(`
    <div class="dialog-box">
      <p>Delete “${escapeHtml(routeLabel(route))}”?</p>
      <div class="dialog-buttons">
        <button class="btn-cancel" type="button">Cancel</button>
        <button class="btn-del" type="button">Delete</button>
      </div>
    </div>`)
  dialog.querySelector(".btn-cancel").onclick = () => closeDialog(dialog)
  dialog.querySelector(".btn-del").onclick = async () => {
    const response = await fetch(`/api/routes/${route.name}`, { method: "DELETE" })
    if (!response.ok) {
      showSnackbar("Delete failed...", "error")
      return
    }
    closeDialog(dialog)
    closeOverlay()
    await refresh()
    showSnackbar("Route deleted!")
  }
}

async function resetRouteName(route, dialog) {
  const response = await fetch("/api/routes/reset_name", {
    method: "POST",
    headers: { "Content-Type": "application/json" },
    body: JSON.stringify({ name: route.name }),
  })
  if (!response.ok) {
    showSnackbar("Resetting name failed...", "error")
    return
  }

  const { timestamp } = await response.json()
  const updatedRoute = normalizeRoute({ ...route, timestamp, isCustomName: false })
  replaceRoute(updatedRoute)
  closeDialog(dialog)
  const title = overlay?.querySelector(".media-player-title-text")
  if (title) title.textContent = routeLabel(updatedRoute)
  showSnackbar("Route name reset!")
}

async function renameRoute(route) {
  const dialog = openDialog(`
    <div class="dialog-box">
      <p>Rename “${escapeHtml(routeLabel(route))}”</p>
      <input class="rn-input" value="${escapeHtml(routeLabel(route))}" aria-label="New route name">
      <div class="dialog-buttons">
        <button class="btn-cancel" type="button">Cancel</button>
        <button class="btn-reset" type="button">Reset</button>
        <button class="btn-save" type="button">Save</button>
      </div>
    </div>`)
  dialog.querySelector(".btn-cancel").onclick = () => closeDialog(dialog)
  dialog.querySelector(".btn-reset").onclick = () => resetRouteName(route, dialog)
  dialog.querySelector(".btn-save").onclick = async () => {
    const newName = dialog.querySelector(".rn-input").value.trim()
    if (!newName) return
    const response = await fetch("/api/routes/rename", {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({ old: route.name, new: newName }),
    })
    if (!response.ok) {
      showSnackbar("Rename failed...", "error")
      return
    }

    const updatedRoute = normalizeRoute({ ...route, timestamp: newName, isCustomName: true })
    replaceRoute(updatedRoute)
    closeDialog(dialog)
    const title = overlay?.querySelector(".media-player-title-text")
    if (title) title.textContent = newName
    showSnackbar("Route renamed!")
  }
}

function formatBytes(bytes) {
  if (!bytes) return "0 MB"
  const megabytes = bytes / 1e6
  return megabytes >= 1000 ? `${(megabytes / 1000).toFixed(2)} GB` : `${megabytes.toFixed(1)} MB`
}

function openLogsDialog(route, logsButton, getCachedLogs, setCachedLogs) {
  const logsDialog = openDialog(`
    <section class="dialog-box route-logs-dialog" role="dialog" aria-modal="true" aria-labelledby="route-logs-title">
      <header class="route-logs-toolbar">
        <div><p class="route-logs-eyebrow">Route data</p><h2 id="route-logs-title">Full logs</h2></div>
        <button class="route-logs-close" type="button" aria-label="Close full logs">&times;</button>
      </header>
      <div class="route-logs-content" aria-live="polite"><p class="route-logs-message">Looking for full logs&hellip;</p></div>
    </section>`)
  const content = logsDialog.querySelector(".route-logs-content")
  const closeButton = logsDialog.querySelector(".route-logs-close")
  const closeLogsDialog = () => {
    document.removeEventListener("keydown", handleKeydown)
    closeDialog(logsDialog)
    logsButton.focus()
  }
  const handleKeydown = event => { if (event.key === "Escape") closeLogsDialog() }
  closeButton.onclick = closeLogsDialog
  logsDialog.addEventListener("click", event => { if (event.target === logsDialog) closeLogsDialog() })
  document.addEventListener("keydown", handleKeydown)
  closeButton.focus()

  const renderLogs = data => {
    content.innerHTML = `
      <div class="route-logs-summary">
        <div><strong>${data.segments.length} segment${data.segments.length === 1 ? "" : "s"}</strong><span>${formatBytes(data.totalBytes)} total download</span></div>
        <a class="route-logs-download-all" href="/api/routes/${route.name}/logs/download" download>Download all <span>.tar</span></a>
      </div>
      <ul class="route-logs-list">
        ${data.segments.map(segment => `<li>
          <div class="route-log-details"><strong>Segment ${Number(segment.segmentNum)}</strong><span>${formatBytes(segment.bytes)} &middot; ${escapeHtml(segment.filename)}</span></div>
          <a class="route-log-download" href="${escapeHtml(segment.url)}" download>Download</a>
        </li>`).join("")}
      </ul>`
  }

  const cachedLogs = getCachedLogs()
  if (cachedLogs) {
    renderLogs(cachedLogs)
    return
  }

  fetch(`/api/routes/${route.name}/logs`)
    .then(async response => ({ response, data: await response.json() }))
    .then(({ response, data }) => {
      if (!response.ok) {
        if (content.isConnected) content.innerHTML = `<p class="route-logs-message route-logs-error">${escapeHtml(data.error || "Could not read logs.")}</p>`
        return
      }
      setCachedLogs(data)
      if (content.isConnected) renderLogs(data)
    })
    .catch(error => {
      if (content.isConnected) content.innerHTML = `<p class="route-logs-message route-logs-error">Could not reach the device: ${escapeHtml(error.message)}</p>`
    })
}

async function openOverlay(route) {
  if (overlay) return
  overlay = document.createElement("div")
  overlay.className = "media-player-overlay dashcam-player-overlay"
  overlay.innerHTML = `
    <section class="media-player-content dashcam-player" role="dialog" aria-modal="true" aria-label="Route player">
      <header class="dashcam-player-header">
        <div><p class="dashcam-player-eyebrow">Dashcam route</p><h2 class="media-player-title-text">${escapeHtml(routeLabel(route))}</h2></div>
        <button class="dashcam-player-close action-close" type="button" aria-label="Close player">&times;</button>
      </header>
      <div class="dashcam-video-shell">
        <video controls muted playsinline></video>
        <div class="dashcam-player-state" role="status">Loading route metadata&hellip;</div>
      </div>
      <div class="dashcam-segment-status" aria-live="polite" hidden></div>
      <div class="dashcam-camera-selector" aria-label="Camera selector">
        <button class="camera-button" data-camera="forward" type="button" disabled hidden>Forward</button>
        <button class="camera-button" data-camera="wide" type="button" disabled hidden>Wide</button>
        <button class="camera-button" data-camera="driver" type="button" disabled hidden>Driver</button>
      </div>
      <div class="dashcam-player-actions">
        <button class="action-download" type="button" disabled><i class="bi bi-download"></i> Download</button>
        <button class="action-logs" type="button"><i class="bi bi-file-earmark-arrow-down"></i> Logs</button>
        <button class="action-rename" type="button"><i class="bi bi-pencil"></i> Rename</button>
        <button class="action-delete" type="button"><i class="bi bi-trash"></i> Delete</button>
      </div>
    </section>`
  document.body.appendChild(overlay)

  const video = overlay.querySelector("video")
  const playerState = overlay.querySelector(".dashcam-player-state")
  const statusStrip = overlay.querySelector(".dashcam-segment-status")
  const downloadButton = overlay.querySelector(".action-download")
  const logsButton = overlay.querySelector(".action-logs")
  const cameraButtons = [...overlay.querySelectorAll(".camera-button")]
  let segments = []
  let current = 0
  let selectedCamera = null
  let logsData = null

  const setPlayerMessage = (message, isError = false) => {
    playerState.textContent = message
    playerState.hidden = !message
    playerState.classList.toggle("error", isError)
  }
  const updateSegmentStatus = () => {
    const status = getSegmentStatus(segments, current)
    statusStrip.textContent = status
    statusStrip.hidden = !status
  }
  const playCurrentSegment = () => {
    if (!segments[current] || !selectedCamera) return
    updateSegmentStatus()
    setPlayerMessage("Loading video…")
    video.src = cameraVideoUrl(segments[current], selectedCamera)
    video.load()
    video.play().catch(() => {})
  }
  const closeOnEscape = event => {
    if (event.key === "Escape" && !document.querySelector(".route-logs-dialog")) closeOverlay()
  }

  overlay.addEventListener("click", event => { if (event.target === overlay) closeOverlay() })
  document.addEventListener("keydown", closeOnEscape)
  overlay._closeOnEscape = closeOnEscape
  overlay.querySelector(".action-close").onclick = closeOverlay
  overlay.querySelector(".action-delete").onclick = () => deleteRoute(state.selectedRoute || route)
  overlay.querySelector(".action-rename").onclick = () => renameRoute(state.selectedRoute || route)

  logsButton.onclick = () => openLogsDialog(route, logsButton, () => logsData, value => { logsData = value })
  downloadButton.onclick = () => {
    if (!selectedCamera) return
    const link = document.createElement("a")
    link.href = `/video/${route.name}/combined?camera=${encodeURIComponent(selectedCamera)}`
    link.download = `${routeLabel(state.selectedRoute || route)}-${selectedCamera}.mp4`
    document.body.appendChild(link)
    link.click()
    link.remove()
  }

  video.addEventListener("loadeddata", () => setPlayerMessage(""))
  video.addEventListener("playing", () => setPlayerMessage(""))
  video.addEventListener("waiting", () => setPlayerMessage("Loading video…"))
  video.addEventListener("error", () => setPlayerMessage("This segment could not be played.", true))
  video.addEventListener("ended", () => {
    if (current + 1 >= segments.length) return
    current += 1
    playCurrentSegment()
  })

  for (const button of cameraButtons) {
    button.addEventListener("click", () => {
      if (button.disabled || button.dataset.camera === selectedCamera || !segments[current]) return
      const playbackTime = Number.isFinite(video.currentTime) ? video.currentTime : 0
      const shouldResume = !video.paused && !video.ended
      selectedCamera = button.dataset.camera
      cameraButtons.forEach(candidate => candidate.classList.toggle("active", candidate === button))
      video.addEventListener("loadedmetadata", () => {
        if (playbackTime > 0) {
          try {
            video.currentTime = Math.min(playbackTime, Number.isFinite(video.duration) ? video.duration : playbackTime)
          } catch (_) {}
        }
        if (shouldResume) video.play().catch(() => {})
      }, { once: true })
      setPlayerMessage("Switching camera…")
      video.src = cameraVideoUrl(segments[current], selectedCamera)
      video.load()
      // Switching cameras deliberately leaves current and the status strip unchanged.
    })
  }

  try {
    const response = await fetch(`/api/routes/${route.name}`)
    if (!response.ok) throw new Error(`Route metadata request failed (${response.status})`)
    const data = await response.json()
    segments = Array.isArray(data.segment_urls) ? data.segment_urls.filter(url => typeof url === "string") : []
    const availableCameras = ["forward", "wide", "driver"].filter(camera => data.available_cameras?.includes(camera))
    if (!segments.length) throw new Error("No video segments are stored for this route")
    if (!availableCameras.length) throw new Error("No camera video is stored for this route")

    selectedCamera = availableCameras.includes("forward") ? "forward" : availableCameras[0]
    for (const button of cameraButtons) {
      const available = availableCameras.includes(button.dataset.camera)
      button.hidden = !available
      button.disabled = !available
      button.classList.toggle("active", button.dataset.camera === selectedCamera)
    }
    downloadButton.disabled = false
    playCurrentSegment()
  } catch (error) {
    cameraButtons.forEach(button => { button.disabled = true })
    setPlayerMessage(error.message || "Could not load this route.", true)
  }
}

function closeOverlay() {
  if (!overlay) return
  document.removeEventListener("keydown", overlay._closeOnEscape)
  overlay.remove()
  overlay = null
  state.selectedRoute = null
}

async function togglePreserved(route, event) {
  event.stopPropagation()
  const isPreserved = !route.is_preserved
  try {
    const response = await fetch(`/api/routes/${route.name}/preserve`, { method: isPreserved ? "POST" : "DELETE" })
    if (!response.ok) {
      const errorData = await response.json()
      showSnackbar(errorData.error || "Failed to update preserved state...", "error")
      return
    }
    replaceRoute({ ...route, is_preserved: isPreserved })
  } catch (_) {
    showSnackbar("An error occurred...", "error")
  }
}

async function deleteAllRoutes() {
  state.showDeleteAllModal = false
  state.isDeletingAll = true
  try {
    const response = await fetch("/api/routes/delete_all", { method: "DELETE" })
    if (!response.ok) throw new Error()
    await refresh()
    showSnackbar("All routes deleted!")
  } catch (_) {
    showSnackbar("An error occurred while deleting all routes...", "error")
  } finally {
    state.isDeletingAll = false
  }
}

function thumbnailFailed(event) {
  event.currentTarget.hidden = true
  event.currentTarget.parentElement?.classList.add("thumbnail-failed")
}

export function RouteRecordings() {
  if (isGalaxyTunnel()) {
    return html`
      <div class="tunnel-notice">
        <div class="tunnel-notice-icon">🛰️</div>
        <h3 class="tunnel-notice-title">Dashcam Routes Unavailable via Galaxy</h3>
        <p class="tunnel-notice-body">Loading dashcam routes requires a direct connection.<br>Connect to your device's local network to use this feature.</p>
      </div>`
  }

  if (state.selectedRoute && !overlay) openOverlay(state.selectedRoute)

  return html`
    <div class="screen-recordings-wrapper dashcam-routes-wrapper">
      <section class="screen-recordings-widget dashcam-library">
        <header class="dashcam-library-header">
          <div><p class="dashcam-library-eyebrow">Local recordings</p><h1>Dashcam Routes</h1></div>
          <button class="dashcam-refresh-button" type="button" @click="${refresh}" disabled="${() => state.loading || false}"><i class="bi bi-arrow-clockwise"></i> Refresh</button>
        </header>

        <div class="dashcam-toolbar">
          <label class="dashcam-search">
            <i class="bi bi-search"></i>
            <input type="search" placeholder="Search names, dates, or route IDs" aria-label="Search routes" value="${() => state.searchQuery}" @input="${event => { state.searchQuery = event.target.value }}">
          </label>
          <label class="dashcam-sort">
            <span>Sort</span>
            <select @change="${event => { state.sortOrder = event.target.value }}">
              <option value="newest" selected="${() => state.sortOrder === "newest" || false}">Newest</option>
              <option value="oldest" selected="${() => state.sortOrder === "oldest" || false}">Oldest</option>
            </select>
          </label>
          <button class="dashcam-preserved-filter" type="button" aria-pressed="${() => String(state.showPreservedOnly)}" @click="${() => { state.showPreservedOnly = !state.showPreservedOnly }}">
            <i class="bi bi-heart-fill"></i> ${() => state.showPreservedOnly ? "Preserved only" : "All routes"}
          </button>
        </div>

        ${() => {
          const view = buildRouteView(state.routes, { preservedOnly: state.showPreservedOnly, searchQuery: state.searchQuery, sortOrder: state.sortOrder })
          const groups = groupRoutesByDate(view.visible)
          return html`
            <div class="dashcam-results-summary" aria-live="polite">
              <span>${view.matching.length} matching route${view.matching.length === 1 ? "" : "s"}</span>
              ${state.loading ? html`<span>Loading ${state.progress} of ${state.total}</span>` : html`<span>${state.routes.length} total</span>`}
            </div>
            ${state.error ? html`<p class="screen-recordings-message dashcam-error">${state.error}</p>` : ""}
            ${state.isDeletingAll ? html`<p class="screen-recordings-message">Deleting routes&hellip;</p>` : ""}
            ${!view.visible.length && state.loading ? html`<div class="dashcam-loading"><span></span><p>Finding local routes&hellip;</p></div>` : ""}
            ${!view.visible.length && !state.loading && !state.isDeletingAll ? html`<div class="dashcam-empty-state"><i class="bi bi-camera-reels"></i><p>${state.routes.length ? "No routes match these filters." : "No routes found."}</p></div>` : ""}
            <div class="dashcam-date-groups">
              ${groups.map(group => html`
                <section class="dashcam-date-group">
                  <h2>${group.label}</h2>
                  <div class="screen-recordings-grid dashcam-routes-grid">
                    ${group.routes.map(route => html`
                      <article class="recording-card dashcam-route-card" @click="${() => { state.selectedRoute = route }}">
                        <button class="preserved-icon" type="button" aria-label="${route.is_preserved ? "Remove preservation" : "Preserve route"}" title="${route.is_preserved ? "Preserved" : "Not preserved"}" @click="${event => togglePreserved(route, event)}">
                          ${() => html`<i class="bi ${route.is_preserved ? "bi-heart-fill" : "bi-heart"}"></i>`}
                        </button>
                        <div class="recording-preview-container dashcam-preview">
                          <span class="dashcam-preview-fallback"><i class="bi bi-camera-video"></i><small>Preview unavailable</small></span>
                          <img src="${route.png}" class="recording-preview" loading="lazy" alt="" @error="${thumbnailFailed}">
                        </div>
                        <div class="dashcam-card-body">
                          <h3>${route.displayName}</h3>
                          ${route.isCustomName ? html`<p class="dashcam-card-date">${route.displayDate}</p>` : ""}
                          <p class="dashcam-card-details"><span>${formatApproxDuration(route.approxDurationSeconds)}</span><span>${route.segmentCount} segment${route.segmentCount === 1 ? "" : "s"}</span></p>
                          <p class="dashcam-preserve-status ${route.is_preserved ? "preserved" : ""}"><i class="bi ${route.is_preserved ? "bi-heart-fill" : "bi-heart"}"></i> ${route.is_preserved ? "Preserved" : "Not preserved"}</p>
                        </div>
                      </article>`)}
                  </div>
                </section>`)}
            </div>
            ${view.truncated ? html`<p class="screen-recordings-message">Showing the first ${MAX_RENDERED_ROUTES} of ${view.matching.length} matching routes.</p>` : ""}`
        }}

        ${() => state.routes.length ? html`
          <footer class="dashcam-danger-zone">
            <div><strong>Delete all local routes</strong><span>Preserved routes are included.</span></div>
            <button class="delete-all-button" type="button" @click="${() => { state.showDeleteAllModal = true }}" disabled="${() => state.isDeletingAll || false}">${() => state.isDeletingAll ? "Deleting…" : "Delete All"}</button>
          </footer>` : ""}
      </section>
      ${() => state.showDeleteAllModal ? Modal({
        title: "Confirm Delete All",
        message: "Are you sure you want to delete all routes? This action cannot be undone...",
        onConfirm: deleteAllRoutes,
        onCancel: () => { state.showDeleteAllModal = false },
        confirmText: "Delete All",
      }) : ""}
    </div>`
}
