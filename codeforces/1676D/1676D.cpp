#include <bits/stdc++.h>

using namespace std;

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int n, m;
    cin >> n >> m;
    int chessboard[n][m];
    int max = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
        cin >> chessboard[i][j];
    }

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        int sum = chessboard[i][j];
        int l = j - 1;
        for (int k = i - 1; k >= 0 && l >= 0; k--)
        {
          sum += chessboard[k][l--];
        }

        l = j + 1;
        for (int k = i - 1; k >= 0 && l < m; k--)
        {
          sum += chessboard[k][l++];
        }

        l = j - 1;
        for (int k = i + 1; k < n && l >= 0; k++)
        {
          sum += chessboard[k][l--];
        }

        l = j + 1;
        for (int k = i + 1; k < n && l < m; k++)
        {
          sum += chessboard[k][l++];
        }
        if(max < sum) max = sum;
      }
    }
    cout << max << endl;
  }
}