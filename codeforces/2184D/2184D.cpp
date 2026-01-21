#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll nck(ll n, ll k) {
  if (k > n)
    return 0;
  if (k == 0 || k == n)
    return 1;
  if (k > n / 2)
    k = n - k;

  ll result = 1;
  for (ll i = 1; i <= k; ++i) {
    result = result * (n - i + 1) / i;
  }
  return result;
}

void solve() {
  ll n, k;
  cin >> n >> k;

  ll b = 63 - __builtin_clzll(n);
  ll ans = 0;
  // cout << b << " bit\n";
  for (int i = b - 1; i >= 0; i--) {
    ll cnt = 0;
    while (cnt <= i) {
      ll cost = i - cnt + cnt * 2 + 1;
      // cout << "For " << cnt << " ones " << "cost: " << cost << "\n";
      if (cost > k) {
        // cout << "Summing: " << nck(i, cnt) << "\n";
        ans += nck(i, cnt);
      }
      cnt++;
    }
  }
  if (b + 1 > k)
    ans++;
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
