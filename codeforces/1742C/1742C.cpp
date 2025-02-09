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
  vector<string> grid(8);
  for (auto &c : grid)
    cin >> c;

  for (int i = 0; i < 8; i++)
  {
    bool flg = 1;
    char f = 'R';
    for (int j = 0; j < 8; j++)
      if (f != grid[i][j])
        flg = 0;
    if (flg)
    {
      cout << 'R' << "\n";
      return;
    }
  }

  for (int i = 0; i < 8; i++)
  {
    bool flg = 1;
    char f = 'B';
    for (int j = 0; j < 8; j++)
      if (f != grid[j][i])
        flg = 0;
    if (flg)
    {
      cout << 'B' << "\n";
      return;
    }
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