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

  if (n == 3)
  {
    cout << "NO" << "\n";
  }
  else
  {
    if (n & 1)
    {
      cout << "YES" << "\n";
      for (int i = 0; i < n; i++)
      {
        if (i & 1)
          cout << n / 2 << " ";
        else
          cout << -(n / 2 - 1) << " ";
      }
    }
    else
    {
      cout << "YES" << "\n";
      for (int i = 0; i < n; i++)
      {
        if (i & 1)
          cout << 1 << " ";
        else
          cout << -1 << " ";
      }
      cout << "\n";
    }
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