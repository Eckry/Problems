#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);
vector<ll> c;
vector<ll> dp(1000001, -1);
ll cSize;
bool flg = 0;
ll dfs(ll n)
{
  if (n == 0)
    flg = 1;
  if (n < 0)
    return 1000000;
  if (dp[n] != -1)
    return dp[n];
  ll ans2 = 1000000;
  for (int i = 0; i < cSize; i++)
  {
    ans2 = min(ans2, dfs(n - c[i]) + 1);
  }
  dp[n] = ans2;
  return dp[n];
}

void solve()
{
  ll n, x;
  cin >> n >> x;
  cSize = n;
  c = vector<ll>(n);
  dp[0] = 0;
  for (auto &d : c)
    cin >> d;
  ll ans = dfs(x);
  if (flg)
    cout << ans << "\n";
  else
    cout << -1 << "\n";
}

int main(void)
{
  optimize();
  int T;
  // cin >> T;
  T = 1;
  while (T--)
    solve();
}