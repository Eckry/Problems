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
  string s1, s2;
  cin >> s1;
  cin >> s2;
  long long int sum = 0;
  int flg = 0;
  for (int i = 0; i < n; i++)
  {
    if ((s1[i] == '0' && s2[i] == '1') || (s2[i] == '0' && s1[i] == '1'))
    {
      flg = 0;
      sum += 2;
    }
    else if (s1[i] == '1' && s2[i] == '1')
    {
      flg = 1;
    }
    else
    {
      if (flg)
      {
        sum += 2;
        flg = 0;
      }
      else
      {
        if (s1[i + 1] == '1' && s2[i + 1] == '1')
        {
          i++;
          sum += 2;
        }
        else
        {
          sum += 1;
        }
      }
    }
  }
  cout << sum << endl;
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