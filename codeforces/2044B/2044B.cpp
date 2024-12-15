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
  for (int i = s.size() - 1; i >= 0; i--)
  {
    if (s[i] == 'q')
    {
      cout << 'p';
    }
    else if (s[i] == 'p')
    {
      cout << 'q';
    }
    else
    {
      cout << s[i];
    }
  }

  cout << "\n";
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