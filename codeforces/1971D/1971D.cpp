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
  int count = 0;

  bool flg = 0;
  for (int i = 0; i < n - 1; i++)
  {
    if (s[i] == '1' && s[i + 1] == '0')
    {
      count++;
    }
    if (flg && s[i] == '0' && s[i + 1] == '1')
    {
      count++;
    }
    if (s[i] == '0' && s[i + 1] == '1')
    {
      flg = 1;
    }
  }

  cout << count + 1 << "\n";
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