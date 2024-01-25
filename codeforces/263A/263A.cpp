#include <bits/stdc++.h>

using namespace std;

int m[5][5];

int solve()
{
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cin >> m[i][j];
      if (m[i][j] == 1)
        return abs(i - 2) + abs(j - 2);
    }
  }
}

int main(void)
{
  cout << solve() << endl;
}