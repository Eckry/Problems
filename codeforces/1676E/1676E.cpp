#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;

  sort(a.begin(), a.end(), greater<>());
  vector<long long> dp(n);
  dp[0] = a[0];
  for (int i = 1; i < n; i++)
  {
    dp[i] = dp[i - 1] + a[i];
  }
  while (q--)
  {
    long long x;
    cin >> x;
    if (x > dp[n - 1])
    {
      cout << -1 << "\n";
      continue;;
    }
    int ans = lower_bound(dp.begin(), dp.end(), x) - dp.begin();
    cout << ans + 1 << "\n";
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