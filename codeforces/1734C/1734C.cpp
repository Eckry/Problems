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
  long long int ans = 0;
  string c = s;
  for (int i = 1; i <= n; i++)
  {
    if (s[i - 1] == '0')
    {
      int j = i - 1;
      while (j < n)
      {
        if (s[j] == '1')
          break;
        if (c[j] == '0')
          ans += i;
        c[j] = '1';
        j += i;
      }
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