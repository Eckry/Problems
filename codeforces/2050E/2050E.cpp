#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  string a, b, c;
  cin >> a >> b >> c;

  int n = a.size();
  int m = b.size();
  const int INF = 1e9 + 1;
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i - 1] == c[i - 1])
      dp[i][0] = dp[i - 1][0];
    else
      dp[i][0] = dp[i - 1][0] + 1;
  }
  for (int i = 1; i <= m; i++) {
    if (b[i - 1] == c[i - 1])
      dp[0][i] = dp[0][i - 1];
    else
      dp[0][i] = dp[0][i - 1] + 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (c[i + j - 1] == a[i - 1]) {
        dp[i][j] = min(dp[i][j], dp[i - 1][j]);
      } else {
        dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
      }
      if (c[i + j - 1] == b[j - 1]) {
        dp[i][j] = min(dp[i][j], dp[i][j - 1]);
      } else {
        dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
      }
    }
  }
  cout << dp[n][m] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
