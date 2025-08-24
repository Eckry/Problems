#include <bits/stdc++.h>

using namespace std;

vector<string> s;
vector<vector<int>> dp;
const int MOD = 1e9 + 7;
int n;

void solve() {
  cin >> n;
  s = vector<string>(n);
  for (auto &c : s)
    cin >> c;
  dp = vector<vector<int>>(n, vector<int>(n, 0));
  if (s[0][0] != '*')
    dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (s[i][j] == '*')
        continue;
      if (i > 0)
        dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
      if (j > 0)
        dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
    }
  }
  cout << dp[n - 1][n - 1] << "\n";
}

int main(void) { solve(); }
