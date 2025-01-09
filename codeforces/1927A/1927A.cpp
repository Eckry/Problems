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
  int f = -1, l = -1;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++)
  {
    if (s[i] == 'B')
    {
      f = i;
      break;
    }
  }

  for (int i = n - 1; i >= 0; i--)
  {
    if (s[i] == 'B')
    {
      l = i;
      break;
    }
  }

  if (l == -1)
  {
    cout << 0 << "\n";
  }
  else if (l == f)
  {
    cout << 1 << "\n";
  }
  else
  {
    cout << l - f + 1 << "\n";
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