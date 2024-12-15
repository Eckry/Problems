#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int m, a, b, c;
  cin >> m >> a >> b >> c;

  int ans = 0;
  if (a > m)
  {
    ans += m;
  }
  else
  {
    ans += a;
    if (c > (m - a))
    {
      ans += m - a;
      c -= m - a;
    }
    else
    {
      ans += c;
      c = 0;
    }
  }

  if (b > m)
  {
    ans += m;
  }
  else
  {
    ans += b;
    if (c > (m - b))
    {
      ans += m - b;
      c -= m - b;
    }
    else
    {
      ans += c;
      c = 0;
    }
  }
  cout << ans << "\n";
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