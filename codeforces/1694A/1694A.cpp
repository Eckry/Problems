#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int a, b;
  cin >> a >> b;
  string ans = "";
  int limit = a + b;
  int i = 0;
  while (i < limit)
  {
    if (b)
    {
      ans += "1";
      b--;
      i++;
    }
    if (a)
    {
      ans += '0';
      a--;
      i++;
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