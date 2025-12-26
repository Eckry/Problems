#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MOD = 998244353;

ll exps(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) {
      res = (res * a) % MOD;
    }
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}

void solve() {
  ll n, m;
  cin >> n >> m;

  if (n == 1) {
    cout << m + 1 << "\n";
    return;
  }

  int bit = 31 - __builtin_clz(m);
  // cout << bit << "\n";
  ll ans = 1;
  for (int i = bit - 1; i >= 0; i--) {
    if (m & (1LL << i)) {
      // cout << i << " " << ans << "\n";
      ans = (ans + exps(2LL, i) + MOD) % MOD;
    }
  }
  cout << (2LL * ans) % MOD << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
