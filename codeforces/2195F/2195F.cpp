#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<vector<ll>> adj;
vector<vector<ll>> adj2;
vector<ll> dp;
vector<ll> dp2;

ll dfs(int v) {
  if (dp[v] != -1)
    return dp[v];

  ll best = 1;
  for (auto u : adj[v]) {
    best = max(best, 1 + dfs(u));
  }
  return dp[v] = best;
}
ll dfs2(int v) {
  if (dp2[v] != -1)
    return dp2[v];

  ll best = 1;
  for (auto u : adj2[v]) {
    best = max(best, 1 + dfs2(u));
  }
  return dp2[v] = best;
}
void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> b(n);
  vector<ll> c(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cin >> b[i];
    cin >> c[i];
  }
  adj = vector<vector<ll>>(n, vector<ll>());
  adj2 = vector<vector<ll>>(n, vector<ll>());
  dp = vector<ll>(n, -1);
  dp2 = vector<ll>(n, -1);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j == i)
        continue;
      ll A = a[i] - a[j];
      ll B = b[i] - b[j];
      ll C = c[i] - c[j];
      if (A != 0) {
        if (A >= 0)
          continue;
        ll d = B * B - 4LL * A * C;
        if (d < 0) {
          adj[j].push_back(i);
          adj2[i].push_back(j);
        }
      } else {
        if (B == 0) {
          if (C < 0) {
            adj[j].push_back(i);
            adj2[i].push_back(j);
          }
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    ll f1 = dfs(i);
    ll f2 = dfs2(i);
    cout << f1 + f2 - 1 << " ";
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
