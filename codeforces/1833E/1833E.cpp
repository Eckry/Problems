#include <bits/stdc++.h>

using namespace std;

#define ll long long
int cnt;
vector<int> a;
vector<set<int>> adj;
vector<int> vis;

int lol;
int dfs(int p, int v) {
  if (vis[v] != -1)
    return adj[v].size() == 1;
  vis[v] = cnt;
  int ok = 0;
  if (adj[v].size() == 1) {
    ok = 1;
  }
  for (auto u : adj[v]) {
    if (p == u)
      continue;
    auto it = dfs(v, u);
    if (it)
      ok = 1;
  }
  return ok;
}

void solve() {
  int n;
  cin >> n;
  a = vector<int>(n);
  vis = vector<int>(n, -1);
  adj = vector<set<int>>(n, set<int>());
  cnt = 0;
  lol = 1;
  for (auto &c : a)
    cin >> c;
  for (int i = 0; i < n; i++) {
    a[i]--;
    adj[i].insert(a[i]);
    adj[a[i]].insert(i);
  }
  int b = 0;
  int c = 0;
  for (int i = 0; i < n; i++) {
    if (vis[i] != -1)
      continue;
    if (dfs(-1, i)) {
      b++;
    }
    cnt++;
  }
  // cout << b << "\n";
  cout << cnt - b + min(b, 1) << " " << cnt << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
