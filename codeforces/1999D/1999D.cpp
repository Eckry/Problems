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
  cin >> s;
  string t;
  cin >> t;
  int start = 0;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == t[start] || s[i] == '?')
    {
      s[i] = t[start];
      start++;
    }
    if (start == t.size())
      break;
  }
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == '?')
      s[i] = 'a';
  }

  if (start == t.size())
  {
    cout << "YES" << "\n";
    cout << s << "\n";
  }
  else
  {
    cout << "NO" << "\n";
  }
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