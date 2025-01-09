#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  long long int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  if (x1 > y1)
  {
    if (x2 > y2)
      cout << "YES" << "\n";
    else
      cout << "NO" << "\n";
  }
  else
  {
    if (y2 > x2)
      cout << "YES" << "\n";
    else cout << "NO" << "\n";
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