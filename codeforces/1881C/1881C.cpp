#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n;
  cin >> n;
  vector<string> m(n);

  for (auto &c : m)
    cin >> c;

  long long int ans = 0;
  for (int i = 0; i < n / 2; i++)
  {
    for (int j = i; j < n - i - 1; j++)
    {
      if (m[i][j] != m[j][n - 1 - i])
      {
        if (m[i][j] > m[j][n - 1 - i])
        {
          ans += m[i][j] - m[j][n - 1 - i];
          m[j][n - 1 - i] = m[i][j];
        }
        else
        {
          ans += m[j][n - 1 - i] - m[i][j];
          m[i][j] = m[j][n - 1 - i];
        }
      }

      if (m[j][n - 1 - i] != m[n - 1 - i][n - 1 - j])
      {
        if (m[j][n - 1 - i] > m[n - 1 - i][n - 1 - j])
        {
          ans += (m[j][n - 1 - i] - m[n - 1 - i][n - 1 - j]);
          m[n - 1 - i][n - 1 - j] = m[j][n - 1 - i];
        }
        else
        {
          ans += (m[n - 1 - i][n - 1 - j] - m[j][n - 1 - i]) * 2;
          m[j][n - 1 - i] = m[n - 1 - i][n - 1 - j];
        }
      }

      if (m[n - 1 - i][n - 1 - j] != m[n - 1 - j][i])
      {
        if (m[n - 1 - i][n - 1 - j] > m[n - 1 - j][i])
        {
          ans += (m[n - 1 - i][n - 1 - j] - m[n - 1 - j][i]);
          m[n - 1 - j][i] = m[n - 1 - i][n - 1 - j];
        }
        else
        {
          ans += (m[n - 1 - j][i] - m[n - 1 - i][n - 1 - j]) * 3;
          m[n - 1 - i][n - 1 - j] = m[n - 1 - j][i];
        }
      }
    }
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