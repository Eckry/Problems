#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                                                             \
  cin.tie(0);                                                                  \
  cin.sync_with_stdio(0);                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cout.tie(0);

ll MOD = 1e9 + 7;
vector<ll> fact(200001);

void solve() {
  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> adj(n + 1);
  for (ll i = 1; i <= m; i++) {
    ll u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  if (m >= n) {
    cout << 0 << "\n";
    return;
  }
  ll leaf = 0;
  ll ans = 1;
  for (int i = 1; i <= n; i++) {
    if (adj[i].size() > 1) {
      ll leaves = 0;
      for (auto u : adj[i]) {
        if (adj[u].size() == 1)
          leaves++;
      }
      if (adj[i].size() - leaves >= 3) {
        cout << 0 << "\n";
        return;
      }
      ans = (ans * fact[leaves]) % MOD;
    } else
      leaf++;
  }
  if (leaf == n) {
    cout << 2 << "\n";
    return;
  }
  if (leaf == n - 1) {
    cout << (2 * ans) % MOD << "\n";
    return;
  }

  cout << (4 * ans) % MOD << "\n";
}

int main() {
  ll T;
  fact[0] = 1LL;
  for (ll i = 1; i <= 200000; i++) {
    fact[i] = (i * fact[i - 1LL]) % MOD;
  }
  cin >> T;
  while (T--)
    solve();
}
