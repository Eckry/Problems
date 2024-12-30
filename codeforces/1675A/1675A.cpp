#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  long long int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  x -= a;
  y -= b;
  long long int need = 0;
  if (x > 0)
  {
    need += x;
  }

  if (y > 0)
  {
    need += y;
  }

  if (need > c)
  {
    cout << "NO" << "\n";
  }
  else
  {
    cout << "YES" << "\n";
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