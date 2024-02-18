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
  int sz = 26;
  vector<bool> wanted(sz, false);
  int m = 0;

  for (auto it : s)
  {
    if (wanted[it - 'a'])
    {
      m += 2;
      for (int i = 0; i < sz; i++)
        wanted[i] = false;
    }
    else
      wanted[it - 'a'] = true;
  }

  cout << (int)s.size() - m << endl;
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