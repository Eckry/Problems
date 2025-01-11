#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  string s;
  cin >> s;

  int n = s.size();

  string ans = "";
  char last = 'X';
  for (int i = 0; i < n; i++)
  {
    if (s[i] == '?')
    {
      if (last == 'X')
      {
        ans += '0';
      }
      else
        ans += last;
    }
    else
    {
      last = s[i];
      ans += s[i];
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