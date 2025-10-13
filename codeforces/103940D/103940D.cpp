#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                                                             \
  cin.tie(0);                                                                  \
  cin.sync_with_stdio(0);                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cout.tie(0);

vector<vector<pair<ll, ll>>> adj;
const ll INF = LONG_LONG_MAX;

void solve() {
  ll n, m;
  cin >> n >> m;
  adj = vector<vector<pair<ll, ll>>>(n + 1, vector<pair<ll, ll>>());
  for (ll i = 0; i < m; i++) {
    ll v, u, c;
    cin >> v >> u >> c;
    adj[v].push_back({u, c});
    adj[u].push_back({v, c});
  }
  vector<pair<ll, ll>> ans(n + 1, pair<ll, ll>({INF, INF}));
  vector<ll> visited(n + 1, 0);
  queue<vector<ll>> q;
  for (int i = 0; i < adj[1].size(); i++) {
    q.push({adj[1][i].first, adj[1][i].second, 1});
  }
  visited[1] = 1;
  ans[1].second = 0;
  ans[1].first = 0;
  while (!q.empty()) {
    auto par = q.front();
    ll v = par[0];
    ll cost = par[1];
    ll dis = par[2];
    q.pop();
    if (ans[v].second < dis)
      continue;
    // cout << v << " " << dis << " " << cost << "\n";
    ans[v].first = min(ans[v].first, dis * cost);
    ans[v].second = dis;
    for (auto u : adj[v]) {
      if (ans[u.first].second < dis + 1)
        continue;
      q.push({u.first, u.second, dis + 1});
    }
  }

  ll sm = 0;

  for (ll i = 1; i <= n; i++) {
    sm += ans[i].first;
    // cout << ans[i].first << " ";
  }
  // cout << "\n";
  cout << sm << "\n";
}

int main() {
  optimize();
  int T;
  T = 1;
  while (T--)
    solve();
}
