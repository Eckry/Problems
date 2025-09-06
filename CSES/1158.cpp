#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n, x;
  cin >> n >> x;
  vector<int> h(n);
  vector<int> s(n);
  for (auto &c : h)
    cin >> c;
  for (auto &c : s)
    cin >> c;
  vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j <= x; j++)
    {
      dp[i][j] = dp[i - 1][j];
      if (j - h[i - 1] >= 0) 
        dp[i][j] = max(dp[i][j], dp[i - 1][j - h[i - 1]] + s[i - 1]);
    }
  }

  cout << dp[n][x] << "\n";
}

int main()
{
  optimize();
  int T;
  T = 1;
  while (T--)
    solve();
}
