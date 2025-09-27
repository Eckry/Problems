#include <bits/stdc++.h>

using namespace std;

#define ll long long

int climbStairs(int n, vector<int> &costs) {
  vector<long long> dp(n + 1);
  dp[0] = 0;
  for (long long i = 1; i <= n; i++) {
    dp[i] = dp[i - 1] + (i) * (i) + costs[i - 1LL];
    for (long long j = 1; j <= 3; j++) {
      if (i - j >= 0) {
        dp[i] = min(dp[i], dp[i - j] + (j) * (j) + costs[i - 1LL]);
      }
    }
  }
  return dp[n];
}
