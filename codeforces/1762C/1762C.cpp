#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MOD = 998244353;

ll e(ll a, ll b) {
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
  ll n;
  cin >> n;
  string s;
  cin >> s;
  ll ans = 1;
  ll acc = 1;
  int cnt = 0;
  for (int i = 1; i < n; i++) {
    if (s[i] == s[i - 1]) {
      cnt++;
    } else {
      cnt = 0;
    }
    ans = (ans + e(2LL, cnt)) % MOD;
  }

  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
