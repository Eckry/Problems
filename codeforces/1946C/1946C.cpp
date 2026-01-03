#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<vector<int>> adj;
int y;
int x;
pair<int, int> check(int p, int v) {
  int sz = 1;
  for (auto u : adj[v]) {
    if (p == u)
      continue;
    auto subtree = check(v, u);
    if (subtree.second >= x) {
      y--;
    } else {
      sz += subtree.second;
    }
  }
  if (sz >= x) {
    if (p != -1)
      y--;
    return {1, (p == -1 ? sz : 0)};
  } else {
    return {1, sz};
  }
}

void solve() {
  int n, k;
  cin >> n >> k;
  adj = vector<vector<int>>(n, vector<int>());
  for (int i = 0; i < n - 1; i++) {
    int v, u;
    cin >> v >> u;
    v--;
    u--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int l = 1;
  int ans = 1;
  int r = n;
  while (l <= r) {
    int m = (l + r) / 2;
    y = k;
    x = m;
    auto res = check(-1, 0);
    if (y < 0 || (res.second >= x && y == 0)) {
      l = m + 1;
      ans = m;
    } else {
      r = m - 1;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
