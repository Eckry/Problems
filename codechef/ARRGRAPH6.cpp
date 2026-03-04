#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<int> vis;
vector<vector<int>> adj;

void dfs(int v, int p) {
  // cout << v << "\n";
  if (vis[v])
    return;
  vis[v] = 1;
  for (auto u : adj[v]) {
    if (u == p)
      continue;
    dfs(u, v);
  }
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }

  vis = vector<int>(n, 0);
  adj = vector<vector<int>>(n, vector<int>());
  sort(a.begin(), a.end());
  vector<int> used(n, 0);
  vector<int> ans(n, -1);
  for (int i = 1; i < n; i++) {
    if (a[i] == a[i - 1])
      continue;
    used[i] = 1;
    int pos = a[i - 1];
    ans[pos] = a[i];
    adj[pos].push_back(a[i]);
    adj[a[i]].push_back(pos);
  }
  // for (int i = 0; i < n; i++) {
  //   cout << used[i] << " ";
  // }
  // cout << "\n";
  int j = 0;
  for (int i = 0; i < n; i++) {
    while (j < n && used[j]) {
      j++;
    }
    if (ans[i] == -1) {
      used[j] = 1;
      // cout << "Using: " << j << " " << a[j] << "\n";
      adj[i].push_back(a[j]);
      adj[a[j]].push_back(i);
      ans[i] = a[j];
    }
  }
  dfs(0, -1);
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      // cout << i << "\n";
      cout << -1 << "\n";
      return;
    }
  }
  for (auto c : ans) {
    cout << c + 1 << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
