    #include <bits/stdc++.h>
     
    using namespace std;
     
    int main(void)
    {
      cin.tie(0);
      cin.sync_with_stdio(0);
     
      int T;
      cin >> T;
     
      while (T--)
      {
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        char square[n][m];
     
        for (int i = 0; i < n; i++)
          for (int j = 0; j < m; j++)
            cin >> square[i][j];
     
        int sum = 0;
     
        for (int i = 0; i < n; i++)
        {
          for (int j = 0; j < m; j++)
          {
            if (square[i][j] != '.')
              continue;
            if (j + 1 < m && square[i][j + 1] == '.')
            {
              square[i][j + 1] = '*';
              sum += min(x * 2, y);
              continue;
            }
            sum += x;
          }
        }
     
        cout << sum << endl;
      }
    }