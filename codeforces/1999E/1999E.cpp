#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

vector<long long> dp(2e5 + 1, -1);

void solve()
{
  int l, r;
  cin >> l >> r;

  if (dp[l] != -1)
  {
    long long sm = 0;
    long long temp = l;
    while (temp)
    {
      temp /= 3;
      sm++;
    }
    cout << dp[r] - dp[l - 1] + sm << "\n";
    return;
  }

  long long ans = 0;

  dp[0] = 0;
  for (int i = 1; i <= 2e5; i++)
  {
    int temp = i;
    int cnt = 0;
    while (temp)
    {
      temp /= 3;
      cnt++;
      if (i == l)
        ans++;
    }
    dp[i] = dp[i - 1] + cnt;
  }

  cout << dp[r] - dp[l - 1] + ans << "\n";
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