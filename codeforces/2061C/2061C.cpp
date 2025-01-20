#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

long long int MOD = 998244353;

void solve()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;

  vector<vector<long long>> dp(n, vector<long long>());
  dp[0][1] = 1; 
  dp[0][0] = 1; 
  for (int i = 1; i < n; i++)
  {
    if (a[i] == a[i - 1])
      dp[i][0] += (dp[i - 1][0] % MOD);
    if (i > 1 && a[i] == a[i - 2] + 1)
      dp[i][0] += (dp[i - 2][0] % MOD);
  }

  cout << (dp[n - 1][0] + dp[n - 2][0]) % MOD << "\n";
}

int main(void)
{
  optimize();
  int T;
  cin >> T;
  // T = 1;
  while (T--)
    solve();
}