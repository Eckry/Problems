#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  string s;
  string t;
  cin >> s >> t;

  map<char, int> mp;
  for (int i = t.size() - 2; i >= 0; i--)
  {
    if (!mp.count(t[i]))
    {
      mp[t[i]] = i;
    }
  }

  int mn = INT_MAX;
  bool flg = 1;
  string ans = "";
  for (int i = 1; i < s.size(); i++)
  {
    if (mp.count(s[i]))
    {
      flg = 0;
      if (mn > i + t.size() - mp[s[i]])
      {
        mn = i + t.size() - mp[s[i]];
        ans = "";
        for (int k = 0; k < i; k++)
        {
          ans += s[k];
        }
        for (int k = mp[s[i]]; k < t.size(); k++)
        {
          ans += t[k];
        }
      }
    }
  }

  if (flg)
  {
    cout << -1 << "\n";
    return;
  }

  cout << ans << " ";
}

int main(void)
{
  optimize();
  int T;
  // cin >> T;
  T = 1;
  while (T--)
    solve();
}