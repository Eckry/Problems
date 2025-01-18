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
  string s;
  cin >> s;
  int ans = n;
  int cnt = 0;
  bool flg = 0;
  int start = -1;
  for (int i = 0; i < n - 1; i++)
  {
    if (flg)
    {
      if (s[i] == ')')
      {
        cnt++;
        ans -= i - start + 1;
        flg = 0;
      }
    }
    else
    {
      if (s[i] == '(')
      {
        ans -= 2;
        cnt++;
        i++;
        continue;
      }
      if (s[i] == ')')
      {
        if (s[i + 1] == ')')
        {
          ans -= 2;
          cnt++;
          i++;
        }
        else
        {
          flg = 1;
          start = i;
          i++;
        }
      }
    }
  }

  if (flg && s[n - 1] == ')' && ans != 0)
  {
    cnt++;
    ans -= n - start;
  }

  cout << cnt << " " << ans << "\n";
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