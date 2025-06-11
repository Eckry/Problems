#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

ll MOD = 1e9 + 7;
vector<ll> dp(1000001, -1);

ll generateDP(ll n)
{
  if (n < 0)
    return 0;
  if (dp[n] != -1)
    return dp[n];
  dp[n] = 0;
  for (int i = 1; i <= 6; i++)
  {
    dp[n] = (dp[n] + generateDP(n - i)) % MOD;
  }
  return dp[n] % MOD ;
}

void solve()
{
  ll n;
  cin >> n;
  cout << dp[n] << "\n";
}

int main(void)
{
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  generateDP(1000000);
  optimize();
  int T;
  // cin >> T;
  T = 1;
  while (T--)
    solve();
}