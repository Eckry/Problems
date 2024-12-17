#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

vector<long long int> dp(2e5 + 1, -1);
long long int limit = 1;
void solve()
{
  long long int n;
  cin >> n;

  if (dp[n] != -1)
  {
    cout << dp[n] << "\n";
    return;
  }

  long long int sm = max(dp[limit - 1], 0LL);
  for (int i = limit; i <= n; i++)
  {
    long long int j = i;
    while (j >= 10)
    {
      sm += j % 10;
      j /= 10;
    }
    sm += j % 10;
    dp[i] = sm;
    limit = i;
  }
  cout << sm << "\n";
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