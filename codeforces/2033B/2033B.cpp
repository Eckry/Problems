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
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> a[i][j];
    }
  }
  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    int k = 0;
    int mn = INT_MAX;
    while (k + i < n)
    {
      mn = min(a[k][k + i], mn);
      k++;
    }
    if (mn < 0)
      ans += abs(mn);
  }

  for (int i = 1; i < n; i++)
  {
    int k = 0;
    int mn = INT_MAX;
    while (k + i < n)
    {
      mn = min(a[k + i][k], mn);
      k++;
    }
    if (mn < 0)
      ans += abs(mn);
  }
  cout << ans << "\n";
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