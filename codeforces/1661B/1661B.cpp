#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

int NUM = 32768;
vector<int> dp(NUM + 1, 15);

void solve()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;

  dp[0] = 0;
  for (int i = 2; i <= NUM; i += 2)
  {
    int temp = i;
    int cnt = 0;
    while (temp)
    {
      if (temp & 1)
        break;
      else
        cnt++;
      temp /= 2;
    }
    dp[i] = 15 - cnt;
  }

  for (int i = 0; i < n; i++)
  {
    int ans = 15;
    int j = 0;
    while (a[i] + j <= NUM && j <= 15)
    {
      ans = min(ans, dp[a[i] + j] + j);
      j++;
    }

    dp[a[i]] = ans;
    cout << ans << " ";
  }
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