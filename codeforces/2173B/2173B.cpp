#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> b(n);
  ll ans = 0;
  for (auto &c : a)
    cin >> c;
  for (auto &c : b)
    cin >> c;
  vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
  for (int i = 0; i < n; i++) {
    dp[i + 1][0] = max(dp[i][0], dp[i][1]) - a[i];
    dp[i + 1][1] = b[i] - min(dp[i][0], dp[i][1]);
  }
  ll mn = 0;
  ll mx = 0;
  for (int i = 0; i < n - 1; i++) {
    ll temp = mx;
    mx = max(mx - a[i], b[i] - mx);
    mx = max(mx, mn - a[i]);
    mx = max(mx, b[i] - mn);
    mn = min(mn - a[i], b[i] - mn);
    mn = min(mn, temp - a[i]);
    mn = min(mn, b[i] - temp);
  }
  // cout << max(max(mx - a[n - 1], b[n - 1] - mx),
  //             max(mn - a[n - 1], b[n - 1] - mn))
  //      << "\n";
  // for (int i = 0; i <= n; i++) {
  //   cout << dp[i][0] << " ";
  // }
  // cout << "\n";
  // for (int i = 0; i <= n; i++) {
  //   cout << dp[i][1] << " ";
  // }
  // cout << "\n";
  ans = max(mx - a[n - 1], b[n - 1] - mx);
  ans = max(ans, max(mn - a[n - 1], b[n - 1] - mn));

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
