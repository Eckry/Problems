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

  int L = 0;
  int O = 0;

  for (int i = 0; i < n - 1; i++)
  {
    if (s[i] == 'L')
      L++;
    if (s[i] == 'O')
      O++;
    int L2 = 0;
    int O2 = 0;
    for (int j = i + 1; j < n; j++)
    {
      if (s[j] == 'L')
        L2++;
      if (s[j] == 'O')
        O2++;
    }
    if (L2 != L && O2 != O)
    {
      cout << i + 1;
      return;
    }
  }
  cout << -1;
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