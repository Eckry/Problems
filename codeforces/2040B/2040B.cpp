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

  if (n < 3)
  {
    cout << n << endl;
    return;
  }

  int x = 2;
  int y = 4;

  while (y < n)
  {
    x++;
    y = 2 * (y + 1);
  }

  cout << x << endl;
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