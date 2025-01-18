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

  vector<vector<int>> ans(n, vector<int>(m));
  ans[0][0] = 1;
  ans[0][1] = 0;
  ans[1][0] = 0;
  ans[1][1] = 1;

  int x = 2;
  int p = 0;
  while (x < m)
  {
    ans[0][x] = p;
    ans[0][x + 1] = 1 - p;
    ans[1][x] = 1 - p;
    ans[1][x + 1] = p;
    p = 1 - p;
    x += 2;
  }

  x = 2;
  p = 0;
  while (x < n)
  {
    for (int i = 0; i < m; i++)
    {
      ans[x][i] = ans[x - 1][i];
      ans[x][i] = ans[x - 1][i];
    }

    for (int i = 0; i < m; i++)
    {
      ans[x + 1][i] = ans[x - 2][i];
      ans[x + 1][i] = ans[x - 2][i];
    }
    x += 2;
  }

  for (auto c : ans)
  {
    for (auto d : c)
      cout << d << " ";
    cout << "\n";
  }
  cout << "\n";
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