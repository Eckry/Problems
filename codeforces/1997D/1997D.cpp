#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<vector<int>> adj;
vector<ll> dp;
vector<ll> a;

void dfs(int v, int p) {
  if (adj[v].size() == 1 && p != -1) {
    dp[v] = a[v];
  } else {
    ll mn = LONG_LONG_MAX;
    for (auto u : adj[v]) {
      if (u == p)
        continue;
      dfs(u, v);
      mn = min(mn, dp[u]);
    }

    if (a[v] < mn) {
      dp[v] = (a[v] + mn) / 2;
    } else {
      dp[v] = mn;
    }
  }
}

void solve() {
  int n;
  cin >> n;
  a = vector<ll>(n);
  adj = vector<vector<int>>(n, vector<int>());
  dp = vector<ll>(n, 0);
  for (auto &c : a)
    cin >> c;
  vector<int> par(n);
  for (int i = 0; i < n - 1; i++) {
    int x;
    cin >> x;
    x--;
    par[i + 1] = x;
    adj[i + 1].push_back(x);
    adj[x].push_back(i + 1);
  }
  dfs(0, -1);
  ll mn = LONG_LONG_MAX;
  for (auto u : adj[0]) {
    mn = min(mn, dp[u]);
  }
  cout << a[0] + mn << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
