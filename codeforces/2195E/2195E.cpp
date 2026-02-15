#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<ll> p;
vector<pair<ll, ll>> adj;
vector<ll> ans;
const ll MOD = 1e9 + 7;

ll dfs(ll v) {
  if (v == 0) {
    return dfs(1);
  }
  ll l = adj[v].first;
  ll r = adj[v].second;
  if (l == 0 && r == 0) {
    return p[v] = 1LL;
  }

  ll left = dfs(l);
  ll right = dfs(r);
  return p[v] = (left + right + 3) % MOD;
}

void acc(ll v, ll k) {
  if (v == 0) {
    acc(1, 0);
    return;
  }
  ans[v] = (k + p[v]) % MOD;
  ll l = adj[v].first;
  ll r = adj[v].second;
  if (l == 0 && r == 0) {
    return;
  }

  acc(l, (k + p[v]) % MOD);
  acc(r, (k + p[v]) % MOD);
}

void solve() {
  ll n;
  cin >> n;
  p = vector<ll>(n + 1);
  p[0] = 0;
  adj = vector<pair<ll, ll>>(n + 1);
  ans = vector<ll>(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    ll l, r;
    cin >> l >> r;

    adj[i].first = l;
    adj[i].second = r;
  }

  dfs(0);
  // for (auto c : p) {
  //   cout << c << " ";
  // }
  // cout << "\n";
  acc(0, 0);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] % MOD << " ";
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
