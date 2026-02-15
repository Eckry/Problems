#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 998244353;

ll expmod(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) {
      res = (res * a) % MOD;
    }
    b >>= 1;
    a = (a * a) % MOD;
  }
  return res;
}

void solve() {
  ll n, m;
  cin >> n >> m;
  vector<pair<ll, ll>> seg(n);
  vector<ll> prob(n);
  ll non = 1;
  for (int i = 0; i < n; i++) {
    cin >> seg[i].first >> seg[i].second;
    ll p, q;
    cin >> p >> q;
    ll x = p * expmod(q, MOD - 2) % MOD;
    ll y = (1 - x + MOD) % MOD;
    non = (non * y) % MOD;
    prob[i] = (x * expmod(y, MOD - 2)) % MOD;
  }

  map<ll, vector<pair<ll, ll>>> mp;
  for (int i = 0; i < n; i++) {
    ll l = seg[i].first;
    ll r = seg[i].second;
    mp[r].push_back({l, prob[i]});
  }
  vector<ll> dp(m + 1, 0);
  dp[0] = 1;
  for (int r = 1; r <= m; r++) {
    for (auto &vec : mp[r]) {
      ll l = vec.first;
      ll p = vec.second;
      dp[r] = (dp[r] + (dp[l - 1] * p) % MOD) % MOD;
    }
  }
  cout << (dp[m] * non) % MOD;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  T = 1;
  while (T--)
    solve();
}
