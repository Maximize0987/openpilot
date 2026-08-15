self.addEventListener("push", (event) => {
  let data = {}
  try {
    data = event.data ? event.data.json() : {}
  } catch {
    data = { body: event.data?.text() || "Sentry event detected." }
  }

  const title = data.title || "StarPilot Sentry Mode"
  const options = {
    body: data.body || "Movement detected while parked.",
    tag: `starpilot-sentry-${data.eventId || "event"}`,
    data: { url: data.url || "/sentry" },
    icon: "/assets/images/favicon.ico",
    badge: "/assets/images/favicon-32x32.png",
    requireInteraction: true,
  }

  event.waitUntil(self.registration.showNotification(title, options))
})

self.addEventListener("notificationclick", (event) => {
  event.notification.close()
  const targetUrl = new URL(event.notification.data?.url || "/sentry", self.location.origin).href

  event.waitUntil(
    clients.matchAll({ type: "window", includeUncontrolled: true }).then((windowClients) => {
      for (const client of windowClients) {
        if ("focus" in client) {
          client.navigate(targetUrl)
          return client.focus()
        }
      }
      return clients.openWindow(targetUrl)
    })
  )
})
