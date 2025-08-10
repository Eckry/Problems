#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                                                             \
  cin.tie(0);                                                                  \
  cin.sync_with_stdio(0);                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cout.tie(0);

vector<vector<int>> adj;
ll ans = 0;
int node = 0;

void dfs(int n, int p) {
  if (p != node && adj[n].size() == 1) {
    ans++;
  }
  for (auto u : adj[n]) {
    if (p == u)
      continue;
    dfs(u, n);
  }
}

void solve() {
  int n;
  cin >> n;

  adj = vector<vector<int>>(n + 1, vector<int>());
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  if (n == 2) {
    cout << 0 << "\n";
    return;
  }
  ans = 0;
  node = 0;
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    int leaves = 0;
    for (auto u : adj[i]) {
      if (adj[u].size() == 1) {
        leaves++;
      }
    }
    if (mx < leaves) {
      mx = leaves;
      node = i;
    }
  }
  dfs(node, -1);
  cout << ans << "\n";
}

int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
}
