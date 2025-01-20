#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  long long n, x, y;
  cin >> n >> x >> y;

  string a;
  string b;
  cin >> a >> b;
  long long ans = 0;
  vector<int> ids;
  for (int i = 0; i < n; i++)
  {
    if (a[i] != b[i])
    {
      ids.push_back(i);
    }
  }
  if (ids.size() & 1)
  {
    cout << -1 << "\n";
    return;
  }
  else if (ids.size() == 0)
  {
    cout << 0 << "\n";
    return;
  }

  int m = ids.size();
  if (x >= y)
  {
    for (int i = 0; i < m / 2; i++)
    {
      if (ids[i + m / 2] - ids[i] != 1)
      {
        ans += y;
      }
      else
      {
        if (2 * y > x)
        {
          ans += x;
        }
        else if (2 * y < x)
        {
          ans += 2 * y;
        }
        else
        {
          ans += x;
        }
      }
    }
    cout << ans << "\n";
  }
  else
  {
    vector<long long> dp(m + 1);
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= m; i++)
    {
      if ((i + 1) % 2 == 1)
      {
        dp[i] = min(dp[i - 2] + 1ll * (ids[i - 1] - ids[i - 2]) * x, dp[i - 1] + y);
      }
      else
      {
        dp[i] = min(dp[i - 2] + 1ll * (ids[i - 1] - ids[i - 2]) * x, dp[i - 1]);
      }
    }
    cout << dp[m] << "\n";
  }
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