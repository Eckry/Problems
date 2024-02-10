#include <bits/stdc++.h>

using namespace std;

int solve()
{
  int R, C;
  cin >> R >> C;
  char yard[R][C];
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++)
      cin >> yard[i][j];

  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
    {
      if (yard[i][j] == 'S')
      {
        if (i - 1 >= 0)
        {
          if (yard[i - 1][j] == 'W')
          {
            cout << "No" << endl;
            return 0;
          }
        }
        if (i + 1 < R)
        {
          if (yard[i + 1][j] == 'W')
          {
            cout << "No" << endl;
            return 0;
          }
        }
        if (j - 1 >= 0)
        {
          if (yard[i][j - 1] == 'W')
          {
            cout << "No" << endl;
            return 0;
          }
        }
        if (j + 1 < C)
        {
          if (yard[i][j + 1] == 'W')
          {
            cout << "No" << endl;
            return 0;
          }
        }
      }
      else if (yard[i][j] != 'W')
        yard[i][j] = 'D';
    }
  }

  cout << "Yes" << endl;
  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++)
      cout << yard[i][j];
    cout << endl;
  }
  return 1;
}

int main(void)
{
  cin.tie(0);
  cin.sync_with_stdio(0);

  solve();
}