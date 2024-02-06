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
    int m;
    cin >> m;
    int count = 0;
    int a;
    cin >> a;
    int last = a;
    for (int i = 1; i < m; i++)
    {
      cin >> a;
      {
        if (last != -1 && last > a)
        {
          last = -1;
          count++;
        }
        else
        {
          last = a;
        }
      }
    }
    cout << count << endl;
  }
}