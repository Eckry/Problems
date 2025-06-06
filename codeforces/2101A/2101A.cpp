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
  int cnt = 1;
  vector<vector<ll>> a(n, vector<ll>(n, -1));
  a[n / 2 - (n % 2 == 0)][n / 2] = 0;

  if (n % 2 == 0)
  {
    a[n / 2][n / 2] = cnt++;
    a[n / 2][n / 2 - 1] = cnt++;
    a[n / 2 - 1][n / 2 - 1] = cnt++;
  }

  for (int i = 0; i < (n - 1) / 2; i++)
  {
    for (int j = n / 2 - 2 * (n % 2 == 0) - i - (n % 2 == 1) + 1; j < n / 2 + i + 1; j++)
    {
      a[n / 2 - 2 * (n % 2 == 0) - i - (n % 2 == 1)][j] = cnt++;
    }

    for (int j = n / 2 - 2 * (n % 2 == 0) - i - (n % 2 == 1); j < n / 2 + i + 1; j++)
    {
      a[j][n / 2 + i + 1] = cnt++;
    }

    for (int j = n / 2 + i + 1; j > n / 2 - 2 * (n % 2 == 0) - i - (n % 2 == 1); j--)
    {
      a[n / 2 + i + 1][j] = cnt++;
    }

    for (int j = n / 2 + i + 1; j >= n / 2 - 2 * (n % 2 == 0) - i - (n % 2 == 1); j--)
    {
      a[j][n / 2 - 2 * (n % 2 == 0) - i - (n % 2 == 1)] = cnt++;
    }
  }
  for (auto c : a)
  {
    for (auto d : c)
      cout << d << " ";
    cout << "\n";
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