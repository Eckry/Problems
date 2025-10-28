#include <bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 998244353;
vector<ll> fact(1000001, 0);

ll mod_exp(ll a) {
  ll x = MOD - 2LL;
  ll res = 1LL;
  while (x) {
    if (x & 1) {
      res = (res * a) % MOD;
    }
    x >>= 1;
    a = (a * a) % MOD;
  }
  return res % MOD;
}

void solve() {
  int q;
  cin >> q;
  while (q--) {
    ll n, k;
    cin >> n >> k;
    ll term1 = (fact[n] * mod_exp(fact[n - k])) % MOD;
    ll term2 = (mod_exp(fact[k]) * (n + 1)) % MOD;
    ll ans = (term1 * term2 % MOD) * mod_exp(k + 1) % MOD;

    cout << ans % MOD << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  fact[0] = 1;
  for (int i = 1; i < 1000001; i++) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }

  int T;
  T = 1;
  while (T--)
    solve();
}
