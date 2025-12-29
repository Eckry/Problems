#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MOD = 998244353;
vector<ll> f(51, 0);

ll e(ll a, ll b) {
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
  vector<ll> a(n + 1);
  for (auto &c : a)
    cin >> c;

  sort(a.begin() + 1, a.end(), greater<ll>());
  ll mx = a[1];
  // cout << mx << "\n";
  for (int i = 1; i <= n; i++) {
    a[0] -= max(0LL, (mx - 1) - a[i]);
    if (a[i] != mx)
      a[i] = mx - 1;
  }
  if (a[0] < 0) {
    cout << 0 << "\n";
    return;
  }
  ll cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] != mx) {
      cnt++;
    }
  }
  ll left = min(a[0], cnt);
  if (left == 0) {
    cout << f[n - cnt] * f[cnt] % MOD << "\n";
    return;
  }
  if (cnt == 0) {
    cout << f[n] << "\n";
    return;
  }
  if (left == cnt) {
    cout << f[n] << "\n";
    return;
  }
  auto nck = [&](ll nn, ll kk) {
    ll term1 = f[nn - kk] * f[kk] % MOD;
    ll cm = f[nn] * e(term1, MOD - 2) % MOD;
    return cm;
  };
  ll ans = 0;
  // cout << ans << "\n";
  for (int i = 0; i <= left; i++) {
    ll F = n - cnt;
    ll cm = nck(cnt, i);
    ll term2 = cm * f[i + F - 1] % MOD;
    ll term3 = f[cnt - i] % MOD;
    term3 = (term3 * F) % MOD;
    ans = (ans + term2 * term3 % MOD) % MOD;
  }

  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  f[0] = 1;
  for (ll i = 1; i <= 50LL; i++) {
    f[i] = (f[i - 1] * i) % MOD;
  }
  int T;
  cin >> T;
  while (T--)
    solve();
}
