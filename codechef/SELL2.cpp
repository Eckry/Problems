#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;
  vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));

  dp[0][1] = a[0];
  dp[0][2] = -10000000000LL;
  for (int i = 1; i < n; i++) {
    for (int x = 1; x <= i + 1; x++) {
      dp[i][x] = dp[i - 1][x];
      if (x >= 2) {
        dp[i][x] = max(dp[i][x], dp[i - 1][x - 2] + 2 * a[i]);
      }
      if (x >= 1) {
        dp[i][x] = max(dp[i][x], dp[i - 1][x - 1] + a[i]);
      }
    }
  }
  cout << dp[n - 1][n] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
