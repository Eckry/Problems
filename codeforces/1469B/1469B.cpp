#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n;
  cin >> n;

  vector<int> sumA(n, 0);
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    if (i)
      sumA[i] = a[i] + sumA[i - 1];
    else
      sumA[i] = a[i];
  }

  int m;
  cin >> m;
  vector<int> sumB(m, 0);
  vector<int> b(m);

  for (int i = 0; i < m; i++)
  {
    cin >> b[i];
    if (i)
      sumB[i] = b[i] + sumB[i - 1];
    else
      sumB[i] = b[i];
  }

  vector<int> x(m + 1, INT_MIN);
  vector<vector<int>> dp(n + 1, x);

  dp[0][0] = 0;

  int ans = INT_MIN;

  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= m; j++)
    {
      if (i < n)
      {
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + a[i]);
      }
      if (j < m)
      {
        dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + b[j]);
      }
      ans = max(dp[i][j], ans);
    }
  }
  cout << max(ans, 0) << endl;
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