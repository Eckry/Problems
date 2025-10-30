#include <bits/stdc++.h>

using namespace std;

#define ll long long
vector<vector<int>> adj;
vector<int> par;
vector<ll> subtree;
int dfs(int v, int p) {
  int sz = 1;
  for (auto u : adj[v]) {
    if (u == p)
      continue;
    par[u] = v;
    int subsz = dfs(u, v);
    sz += subsz;
  }
  subtree[v] = sz;
  return sz;
}

void solve() {
  ll n;
  cin >> n;
  adj = vector<vector<int>>(n, vector<int>());
  par = vector<int>(n, -1LL);
  subtree = vector<ll>(n, -1LL);
  vector<pair<int, int>> edges;
  for (int i = 0; i < n - 1; i++) {
    int v, u;
    cin >> v >> u;
    v--;
    u--;
    adj[u].push_back(v);
    adj[v].push_back(u);
    edges.push_back({u, v});
  }
  dfs(0, -1);
  ll ans = 0;
  ll cnt = 0;
  for (int i = 0; i < n - 1; i++) {
    int v = edges[i].first;
    int u = edges[i].first;
    if (par[v] == u) {
      swap(v, u);
    }
    ll comb = (n - subtree[v]) * subtree[v];
    if (comb > ans) {
      cnt = 1;
      ans = comb;
    } else if (comb == ans) {
      cnt++;
    }
  }
  cout << ans << " " << cnt << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  T = 1;
  while (T--)
    solve();
}
