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
  int n;
  cin >> n;
  string s;
  cin >> s;
  map<char, int> mp;
  for (int i = 0; i < n; i++)
  {
    mp[s[i]]++;
  }

  char let = '1';
  char rep = '1';
  ll mx = -1;
  ll mn = INT_MAX;
  for (auto c : mp)
  {
    if (mx < c.second)
    {
      mx = c.second;
      let = c.first;
    }
    if (mn > c.second)
    {
      mn = c.second;
      rep = c.first;
    }
  }

  for (int i = 0; i < n; i++)
  {
    if (rep == let && s[i] != rep)
    {
      s[i] = let;
      break;
    }
    if (rep != let && s[i] == rep)
    {
      s[i] = let;
      break;
    }
  }
  cout << s << "\n";
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