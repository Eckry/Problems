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
  string s1 = "";
  s1 += s[0];
  string s2 = "";

  int start = 1;
  for (int i = start; i < n; i++)
  {
    start = i;
    if (s[i] == '0')
    {
      s1 += s[i];
    }
    else
    {
      break;
    }
  }

  for (int i = start; i < n; i++)
  {
    s2 += s[i];
  }

  int ans = 0;
  for (int i = 0; i < s1.size(); i++)
  {
    ans += (s1[i] - '0') * pow(10, s1.size() - 1);
  }

  int ans2 = 0;
  for (int i = 0; i < s2.size(); i++)
  {
    ans2 += (s2[i] - '0') * pow(10, s2.size() - i - 1);
  }

  if (ans >= ans2)
    cout << -1 << "\n";
  else
    cout << ans << " " << ans2 << "\n";
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