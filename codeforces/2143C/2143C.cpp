#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                                                             \
  cin.tie(0);                                                                  \
  cin.sync_with_stdio(0);                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cout.tie(0);

vector<vector<int>> adj;
vector<int> visited;
vector<int> ans;
int num;

void dfs(int n, int p) {
  if (visited[n])
    return;
  visited[n] = 1;
  // cout << n << "\n";

  for (auto v : adj[n]) {
    if (v == p)
      continue;
    dfs(v, n);
  }
  ans[n] = num;
  num++;
}

void solve() {
  ll n;
  cin >> n;
  num = 1;
  ans = vector<int>(n + 1, 0);
  adj = vector<vector<int>>(n + 1, vector<int>());
  visited = vector<int>(n + 1, 0);
  for (int i = 0; i < n - 1; i++) {
    ll u, v, x, y;
    cin >> u >> v >> x >> y;
    if (x < y) {
      adj[v].push_back(u);
    } else {
      adj[u].push_back(v);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (visited[i])
      continue;
    dfs(i, -1);
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}

int main() {
  optimize() int T;
  cin >> T;
  while (T--)
    solve();
}
