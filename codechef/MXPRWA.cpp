#include <bits/stdc++.h>

using namespace std;

#define ll long long
vector<ll> a;
vector<vector<int>> adj;
ll best;
vector<int> odd;
vector<ll> acc;
ll sm;
const ll MOD = 998244353;

ll exp_mod(ll a, ll b) {
  ll res = 1LL;
  while (b) {
    if (b & 1) {
      res = (res * a) % MOD;
    }
    a = (a * a) % MOD;
    b >>= 1LL;
  }
  return res;
}

void dfs(int v, int p) {
  odd[v] = a[v] < 0;
  acc[v] = abs(a[v]);

  for (auto u : adj[v]) {
    if (p == u)
      continue;
    dfs(u, v);
    odd[v] ^= odd[u];
    acc[v] += acc[u];
  }
  if (odd[v]) {
    best = max(best, sm - acc[v]);
  } else {
    best = max(best, acc[v]);
  }
}

void solve() {
  int n;
  cin >> n;
  a = vector<ll>(n);
  best = 0;
  for (auto &c : a)
    cin >> c;
  adj = vector<vector<int>>(n, vector<int>());
  ll par = 0;
  sm = 0;
  for (int i = 0; i < n - 1; i++) {
    int v, u;
    cin >> v >> u;
    v--;
    u--;
    adj[v].push_back(u);
    adj[u].push_back(v);
  }
  for (int i = 0; i < n; i++) {
    sm += abs(a[i]);
    par ^= a[i] < 0;
  }
  if (!par) {
    cout << exp_mod(2, sm) << "\n";
  } else {
    odd = vector<int>(n, 0);
    acc = vector<ll>(n, 0);
    dfs(0LL, -1LL);
    cout << exp_mod(2, best) << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
