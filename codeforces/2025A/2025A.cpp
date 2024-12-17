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
  string t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();

  int i = 0;

  while (s[i] == t[i])
  {
    if (i >= n || i >= m)
      break;
    i++;
  }

  if (i == 0)
  {
    cout << n + m << "\n";
  }
  else
  {
    cout << n - i + m + 1 << "\n";
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