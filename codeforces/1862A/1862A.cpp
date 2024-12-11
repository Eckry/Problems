#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n, m;
  cin >> n >> m;

  vector<string> a(n);

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  char look = 'v';
  char last = '0';

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (a[j][i] == 'v' && last == '0')
      {
        last = 'v';
        look = 'i';
        break;
      }
      if (a[j][i] == 'i' && last == 'v')
      {
        last = 'i';
        look = 'k';
        break;
      }
      if (a[j][i] == 'k' && last == 'i')
      {
        last = 'k';
        look = 'a';
        break;
      }
      if (a[j][i] == 'a' && last == 'k')
      {
        look = 'n';
        break;
      }
    }
  }

  string ans = look == 'n' ? "YES" : "NO";

  cout << ans << endl;
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