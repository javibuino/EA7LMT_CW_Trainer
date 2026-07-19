// Service Worker — EA7LMT CW Trainer
// Cache-first strategy for the whole app shell, so the trainer keeps
// working with no signal at all (portable/SOTA/POTA use). Bump
// CACHE_NAME any time index.html or the icon set changes, so returning
// users pick up the new version instead of a stale cached one.
const CACHE_NAME = 'ea7lmt-cw-trainer-v1';

const APP_SHELL = [
  './',
  './index.html',
  './manifest.json',
  './icons/icon.svg',
  './icons/favicon-16.png',
  './icons/favicon-32.png',
  './icons/apple-touch-icon.png',
  './icons/icon-192.png',
  './icons/icon-512.png'
];

self.addEventListener('install', (event) => {
  event.waitUntil(
    caches.open(CACHE_NAME).then(async (cache) => {
      // Cache each file independently: if one icon path doesn't exist
      // (e.g. a size that wasn't generated), the rest of the app shell
      // still gets cached instead of the whole install failing.
      await Promise.allSettled(
        APP_SHELL.map((url) => cache.add(url).catch(() => {}))
      );
    }).then(() => self.skipWaiting())
  );
});

self.addEventListener('activate', (event) => {
  event.waitUntil(
    caches.keys().then((names) =>
      Promise.all(
        names.filter((name) => name !== CACHE_NAME)
             .map((name) => caches.delete(name))
      )
    ).then(() => self.clients.claim())
  );
});

// Cache-first, falling back to network, and updating the cache with
// whatever the network returns (so the app slowly self-updates while
// online without needing a manual re-deploy step for the SW itself).
self.addEventListener('fetch', (event) => {
  if (event.request.method !== 'GET') return;

  event.respondWith(
    caches.match(event.request).then((cached) => {
      const networkFetch = fetch(event.request).then((response) => {
        if (response && response.status === 200) {
          const clone = response.clone();
          caches.open(CACHE_NAME).then((cache) => cache.put(event.request, clone));
        }
        return response;
      }).catch(() => cached);

      return cached || networkFetch;
    })
  );
});
