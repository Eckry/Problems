#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct DSU {
  vector<int> par;
  vector<int> sz;
  DSU(int n) {
    par.resize(n);
    sz.assign(n, 1);
    iota(par.begin(), par.end(), 0);
  }

  int find_leader(int v) {
    if (v == par[v])
      return v;
    return par[v] = find_leader(par[v]);
  }

  void make_union(int v, int u) {
    int a = find_leader(v);
    int b = find_leader(u);
    if (a == b)
      return;
    if (sz[a] < sz[b])
      swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> e(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    e[i].first = x;
    e[i].second = i;
  }
  vector<vector<int>> adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int v, u;
    cin >> v >> u;
    v--;
    u--;
    adj[v].push_back(u);
    adj[u].push_back(v);
  }

  sort(e.begin(), e.end(),
       [&](pair<int, int> a, pair<int, int> b) { return a.first < b.first; });

  vector<int> activate(n, 0);
  vector<int> ans(n);
  DSU dsu(n);
  for (int i = 0; i < n;) {
    int j = i;
    while (j < n && e[j].first == e[i].first)
      j++;
    for (int k = i; k < j; k++) {
      activate[e[k].second] = 1;
    }

    for (int k = i; k < j; k++) {
      int v = e[k].second;
      for (auto u : adj[v]) {
        if (activate[u]) {
          dsu.make_union(v, u);
        }
      }
    }

    for (int k = i; k < j; k++) {
      int v = e[k].second;
      int par = dsu.find_leader(v);
      ans[v] = dsu.sz[par];
    }
    i = j;
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  T = 1;
  while (T--)
    solve();
}
