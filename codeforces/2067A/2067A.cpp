#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int x, y;
  cin >> x >> y;
  if (y - x == 1)
  {
    cout << "YES" << "\n";
    return;
  }
  int k = 8;
  while (k <= 1000)
  {
    if (x - y == k)
    {
      cout << "YES" << "\n";
      return;
    }
    k += 9;
  }

  cout << "NO" << "\n";
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