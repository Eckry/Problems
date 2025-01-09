#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int a, b;
  cin >> a >> b;
  // -101 -100 501

  if (a == b)
  {
    cout << 3 << "\n";
    cout << a << " " << a << " " << a << "\n";
    return;
  }

  int x = a, y = a, z = a;

  int total = a * 3;
  cout << 3 << "\n";
  if (b > 0)
  {
    if (total - b * 2 - 1 < b)
    {
      cout << total - b * 2 - 1 << " " << b << " " << b + 1 << "\n";
    }
    else
    {
      cout << b - 1 << " " << b << " " << total - b * 2 + 1 << "\n";
    }
  }
  else if (b < 0)
  {
    if (total > 0)
    {
      cout << total - b * 2 + 1 << " " << b << " " << b - 1 << "\n";
    }
    else if (total < 0)
    {
      cout << -total - b * 2 + 1 << " " << b << " " << b - 1 + total * 2 << "\n";
    }
    else
    {
      cout << -b * 3 << " " << b << " " << b * 2 << "\n";
    }
  }
  else
  {
    cout << total - b * 2 + 1 << " " << b << " " << b - 1 << "\n";
  }
}

int main(void)
{
  optimize();
  int T;
  T = 1;
  while (T--)
    solve();
}