#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MOD = 1e9 + 7;

ll mod_exp(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) {
      res = (res * a) % MOD;
    }
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res % MOD;
}

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;

  vector<ll> suf(n + 1, 0);
  for (int i = n - 1; i >= 0; i--) {
    suf[i] = (suf[i + 1] + a[i]) % MOD;
  }
  // for (auto c : suf) {
  //   cout << c << " ";
  // }
  // cout << "\n";

  ll sm = 0;
  for (int i = 0; i < n; i++) {
    sm = (sm + (a[i] * suf[i + 1]) % MOD) % MOD;
  }
  // 15 + 6
  ll mult = (n * (n - 1 + MOD)) % MOD;
  mult = (mult * mod_exp(2, MOD - 2)) % MOD;
  cout << (sm * mod_exp(mult, MOD - 2)) % MOD << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
