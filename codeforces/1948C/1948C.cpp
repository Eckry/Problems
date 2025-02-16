#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

int n;
vector<vector<vector<int>>> dp;
bool check(vector<string> &a, int i, int j, int forced)
{
  if (dp[i][j][forced] != -1)
  {
    return dp[i][j][forced];
  }

  if (j == n - 1 && i == 1)
  {
    dp[i][j][forced] = 1;
    return 1;
  }
  if (forced && a[i][j] == '<')
  {
    dp[i][j][forced] = 0;
    return 0;
  }
  else if (forced && a[i][j] == '>')
  {
    dp[i][j][forced] = check(a, i, j + 1, 0);
    return dp[i][j][forced];
  }
  if (j == n - 1)
  {
    dp[i][j][forced] = (check(a, 1 - i, j, 1));
    return dp[i][j][forced];
  }
  else
  {
    dp[i][j][forced] = (check(a, 1 - i, j, 1) || check(a, i, j + 1, 1));
    return dp[i][j][forced];
  }
}

void solve()
{
  cin >> n;
  vector<string> a(2);
  dp = vector<vector<vector<int>>>(2, vector<vector<int>>(n, vector<int>(2, -1)));
  cin >> a[0];
  cin >> a[1];
  if (check(a, 0, 0, 0))
    cout << "YES" << "\n";
  else
    cout << "NO" << "\n";
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