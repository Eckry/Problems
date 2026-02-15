#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;

  if (n == 1) {
    cout << 0 << "\n";
    return;
  }
  vector<int> ok(n, 0);
  int ans = 0;

  vector<vector<int>> dp(n + 1, vector<int>(2, 0));
  dp[1][1] = 1;
  for (int i = 1; i < n; i++) {
    if (a[i - 1] == 7 - a[i] || a[i] == a[i - 1]) {
      dp[i + 1][1] = dp[i][0] + 1;
      dp[i + 1][0] = dp[i][1];
    } else {
      dp[i + 1][0] = min(dp[i][0], dp[i][1]);
      dp[i + 1][1] = min(dp[i][0], dp[i][1]) + 1;
    }
  }
  // for (int i = 1; i <= n; i++) {
  //   cout << dp[i][0] << " ";
  // }
  // cout << "\n";
  // for (int i = 1; i <= n; i++) {
  //   cout << dp[i][1] << " ";
  // }
  // cout << "\n";
  if (a[n - 1] == 7 - a[n - 2] || a[n - 1] == a[n - 2])
    cout << min(dp[n][1], dp[n - 1][1]) << "\n";
  else
    cout << dp[n - 1][0] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
