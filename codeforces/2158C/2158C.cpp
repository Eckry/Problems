#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  vector<ll> b(n);
  for (auto &c : a)
    cin >> c;
  for (auto &c : b)
    cin >> c;
  if (k & 1) {
    vector<vector<ll>> dp(n, vector<ll>(2, 0));
    dp[0][0] = a[0];
    dp[0][1] = b[0] + a[0];
    for (int i = 1; i < n; i++) {
      dp[i][0] = max(dp[i - 1][0] + a[i], a[i]);
      dp[i][1] = max(dp[i - 1][0] + b[i] + a[i], b[i] + a[i]);
      dp[i][1] = max(dp[i - 1][1] + a[i], dp[i][1]);
    }
    ll ans = dp[0][1];
    for (int i = 0; i < n; i++) {
      // cout << dp[i][1] << " ";
      ans = max(ans, dp[i][1]);
    }
    // cout << "\n";
    // for (int i = 0; i < n; i++) {
    //   cout << dp[i][0] << " ";
    // }
    // cout << "\n";
    cout << ans << "\n";
  } else {
    ll ans = a[0];
    ll sm = 0;
    for (int i = 0; i < n; i++) {
      sm = max(sm + a[i], a[i]);
      ans = max(ans, sm);
    }
    cout << ans << "\n";
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
