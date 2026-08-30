import { html, reactive } from "/assets/vendor/arrow-core.js"

const state = reactive({
  loading: true,
  busy: "",
  available: false,
  offroad: false,
  devices: [],
  joystickDevice: "",
  mappings: [],
  slots: [],
  learning: false,
  learningSlot: null,
  remainingSeconds: 0,
  testing: false,
  lastTested: null,
  error: "",
})

let initialized = false

async function refresh() {
  try {
    const response = await fetch("/api/wheel-controls/status", { cache: "no-store" })
    const payload = await response.json()
    if (!response.ok) throw new Error(payload.error || "Wheel controls are unavailable")
    state.available = !!payload.available
    state.offroad = !!payload.offroad
    state.devices = Array.isArray(payload.devices) ? payload.devices : []
    state.joystickDevice = typeof payload.joystick_device === "string" ? payload.joystick_device : ""
    state.mappings = Array.isArray(payload.mappings) ? payload.mappings : []
    state.slots = Array.isArray(payload.slots) ? payload.slots : []
    state.learning = !!payload.learning
    state.learningSlot = Number.isInteger(payload.learning_slot) ? payload.learning_slot : null
    state.remainingSeconds = Number(payload.remaining_seconds || 0)
    state.testing = !!payload.testing
    state.lastTested = payload.last_tested && typeof payload.last_tested === "object" ? payload.last_tested : null
    state.error = ""
  } catch (error) {
    state.available = false
    state.error = error?.message || "Wheel controls are unavailable"
  } finally {
    state.loading = false
  }
}

async function request(operation, body = {}) {
  state.busy = operation
  try {
    const response = await fetch(`/api/wheel-controls/${operation}`, {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify(body),
    })
    const payload = await response.json()
    if (!response.ok) throw new Error(payload.error || "Wheel control operation failed")
    state.error = ""
    await refresh()
  } catch (error) {
    state.error = error?.message || "Wheel control operation failed"
  } finally {
    state.busy = ""
  }
}

function initialize() {
  if (initialized) return
  initialized = true
  refresh()
  setInterval(() => {
    if (window.location.pathname === "/wheel-controls") refresh()
  }, 750)
}

function mappingRow(mapping) {
  return html`
    <div class="wheelMapping">
      <div>
        <strong>${mapping.event_name}</strong>
        <span>${mapping.device_name}</span>
      </div>
      <button class="danger" disabled="${() => !state.offroad || !!state.busy}"
              @click="${() => request("delete", { id: mapping.id })}">Remove</button>
    </div>
  `
}

function slotCard(slot, index) {
  const configured = !!slot?.enabled && !!slot?.key
  const mappings = () => state.mappings.filter(mapping => mapping.slot === index)
  const learning = () => state.learning && state.learningSlot === index
  return html`
    <section class="wheelCard">
      <div class="wheelCardHeader">
        <div>
          <span class="wheelSlotLabel">Favorite #${index + 1}</span>
          <h3>${configured ? (slot.label || slot.key) : "Not configured"}</h3>
        </div>
        <button class="${() => learning() ? "learning" : ""}"
                disabled="${() => !configured || !state.offroad || state.testing || !!state.busy}"
                @click="${() => request(learning() ? "cancel" : "learn", { slot: index })}">
          ${() => learning() ? `Listening (${Math.ceil(state.remainingSeconds)}s)` : "Learn Button"}
        </button>
      </div>
      ${!configured ? html`
        <p class="wheelHint">Choose and enable this slot in <a href="/device_settings/favorites">Toggles → Favorites</a>.</p>
      ` : html`
        <p class="wheelHint">Pressing any mapped button will run this favorite.</p>
      `}
      ${() => learning() ? html`
        <div class="wheelLearnPrompt"><span></span>Press one button on your controller, macropad, or keyboard.</div>
      ` : ""}
      <div class="wheelMappings">
        ${() => mappings().length ? mappings().map(mappingRow) : html`<span class="wheelEmpty">No buttons mapped.</span>`}
      </div>
    </section>
  `
}

function testResultClass() {
  if (!state.lastTested) return "waiting"
  return state.lastTested.mapped ? "success" : "failure"
}

function testPanel() {
  return html`
    <section class="${() => `wheelTestPanel ${testResultClass()}`}">
      <div class="wheelTestIndicator">
        <span></span>
        <strong>${() => {
          if (!state.lastTested) return "Waiting for a button"
          return state.lastTested.mapped ? "Successful" : "Not mapped"
        }}</strong>
      </div>
      <p>${() => {
        if (!state.lastTested) return "Press a button to verify its mapping. Controller inputs are temporarily consumed while testing is enabled."
        const device = state.lastTested.device_name || "External input"
        const button = state.lastTested.event_name || `Button ${state.lastTested.event_code}`
        return state.lastTested.mapped
          ? `${button} on ${device} is mapped to Favorite #${Number(state.lastTested.slot) + 1}.`
          : `${button} on ${device} does not have a mapping.`
      }}</p>
    </section>
  `
}

function deviceRow(device) {
  const selected = () => state.joystickDevice === device.device_id
  return html`
    <div class="wheelDeviceRow">
      <div>
        <strong>${device.name}</strong>
        <span>${device.joystick_capable ? "Buttons and joystick axes" : "Buttons only"}</span>
      </div>
      ${device.joystick_capable ? html`
        <button class="${() => selected() ? "joystickEnabled" : ""}"
                disabled="${() => !state.offroad || !!state.busy}"
                @click="${() => request("joystick", { device_id: device.device_id, enabled: !selected() })}">
          ${() => selected() ? "Enabled for Joystick Mode" : "Enable for Joystick Mode"}
        </button>
      ` : ""}
    </div>
  `
}

export function WheelControls() {
  initialize()
  return html`
    <div class="wheelControlsPage">
      <header class="wheelHeader">
        <div>
          <h2>Controllers</h2>
          <p>Map buttons to favorites, or explicitly select one gamepad for Joystick Mode.</p>
        </div>
        <div class="wheelHeaderActions">
          <button class="${() => state.testing ? "testing" : ""}"
                  disabled="${() => !state.offroad || !state.mappings.length || !!state.busy}"
                  @click="${() => request(state.testing ? "test-stop" : "test")}">
            ${() => state.testing ? "Stop Testing" : "Test Buttons"}
          </button>
          <button class="danger" disabled="${() => !state.offroad || !state.mappings.length || !!state.busy}"
                  @click="${() => {
                    if (window.confirm("Remove every controller mapping?")) request("clear")
                  }}">Clear All</button>
        </div>
      </header>

      ${() => !state.offroad ? html`<div class="wheelNotice">Mappings can only be learned or changed while offroad. Mapped buttons continue working onroad.</div>` : ""}
      ${() => state.error ? html`<div class="wheelError">${state.error}</div>` : ""}
      ${() => !state.loading && !state.available && state.mappings.length ? html`<div class="wheelNotice">The wheel control service is starting.</div>` : ""}
      ${() => state.testing ? testPanel() : ""}

      <div class="wheelDeviceSummary">
        <div class="wheelDeviceHeading">
          <strong>Connected input devices</strong>
          <span>Favorite buttons are the default. Only the selected gamepad controls Joystick Mode.</span>
        </div>
        ${() => state.devices.length
          ? html`<div class="wheelDeviceList">${state.devices.map(deviceRow)}</div>`
          : html`<span class="wheelMuted">Connect or pair a controller, macropad, or keyboard.</span>`}
      </div>

      <div class="wheelSlotGrid">
        ${() => state.loading ? html`<div class="wheelCard">Loading...</div>` : state.slots.map(slotCard)}
      </div>
    </div>
  `
}
