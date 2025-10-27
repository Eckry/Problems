#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct Node {
  ll x, y, z;
};

void solve() {
  ll n, h, k;
  cin >> n >> h >> k;
  vector<Node> a(n + 1);
  for (int i = 0; i < n; i++) {
    ll x, y, z;
    cin >> x >> y >> z;
    a[i].x = x;
    a[i].y = -y;
    a[i].z = z;
  }
  ll a2, b;
  cin >> a2 >> b;
  b = -b;
  if (b == 0) {
    cout << 0 << "\n";
    return;
  }
  ll length = max(h, k);
  map<pair<ll, ll>, vector<ll>> mp;
  for (int i = 0; i < n; i++) {
    ll cx = a[i].x / length;
    ll cy = (a[i].y + length - 1) / length;
    auto par = make_pair(cx, cy);
    mp[par].push_back(i);
  }

  ll start = -1;
  for (int i = 0; i < n; i++) {
    if (a2 == a[i].x && b == a[i].y) {
      start = i;
    }
  }
  vector<ll> visited(n + 1, 0);
  vector<ll> dist(n + 1, -1);
  dist[start] = 0;
  queue<ll> q;
  q.push(start);
  while (!q.empty()) {
    ll v = q.front();
    q.pop();
    if (visited[v])
      continue;
    visited[v] = 1;
    ll x = a[v].x;
    ll y = a[v].y;
    ll z = a[v].z;
    for (int dx = -1; dx <= 1; dx++) {
      for (int dy = -1; dy <= 1; dy++) {
        auto cell = make_pair(x / length + dx, (y + length - 1) / length + dy);
        // cout << x << " " << y << " " << v << "\n";
        if (z && y <= h) {
          cout << dist[v] + 1;
          return;
        }
        if (mp.count(cell)) {
          for (auto u : mp[cell]) {
            ll x2 = a[u].x;
            ll y2 = a[u].y;
            ll z2 = a[u].z;
            if (z) {
              if ((x - x2) * (x - x2) + (y - y2) * (y - y2) <= h * h) {
                if (dist[u] == -1)
                  dist[u] = dist[v] + 1;
                q.push(u);
              }
            }
            if (z2 && (x - x2) * (x - x2) + (y - y2) * (y - y2) <= k * k) {
              if (dist[u] == -1)
                dist[u] = dist[v] + 1;
              q.push(u);
            }
          }
        }
      }
    }
  }
  cout << -1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  T = 1;
  while (T--)
    solve();
}
