#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n, a, b;
  cin >> n >> a >> b;

  string s;
  cin >> s;

  int x = 0, y = 0;

  int t = 20;
  while (t--)
  {
    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == 'N')
      {
        y++;
      }
      if (s[i] == 'S')
      {
        y--;
      }
      if (s[i] == 'E')
      {
        x++;
      }
      if (s[i] == 'W')
      {
        x--;
      }
      if (x == a && y == b)
      {
        cout << "YES" << "\n";
        return;
      }
    }
    if (x == 0 && y == 0)
      break;
  }

  cout << "NO" << "\n";
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