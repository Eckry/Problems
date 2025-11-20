#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MOD = 1e9 + 7;

ll dp[1000001][2];
void solve() {
  int n;
  cin >> n;
  cout << (dp[n - 1][0] + dp[n - 1][1]) % MOD << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  dp[0][1] = 1;
  dp[0][0] = 1;
  for (int i = 1; i < 1000001; i++) {
    dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] * 2LL) % MOD;
    dp[i][0] = (dp[i - 1][1] + dp[i - 1][0] * 4LL) % MOD;
  }
  int T;
  cin >> T;
  while (T--)
    solve();
}
