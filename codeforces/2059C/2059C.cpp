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
  vector<vector<ll>> a(n, vector<ll>(n));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> a[i][j];

  vector<ll> suff(n, 0);
  for (int i = 0; i < n; i++)
  {
    for (int j = n - 1; j > 0; j--)
    {
      if (a[i][j] != 1)
        break;
      suff[i]++;
    }
  }

  multiset<ll> num;
  for (int i = 0; i < n; i++)
    num.insert(suff[i]);
  int ans = 1;

  while (!num.empty())
  {
    auto cur = num.begin();
    if (*cur >= ans)
    {
      ans++;
    }
    num.erase(cur);
  }

  cout << min(ans, n) << "\n";
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