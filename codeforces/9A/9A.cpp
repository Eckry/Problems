#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

int eu(int a, int b)
{
  return a % b == 0 ? b : eu(b, a % b);
}

void solve()
{
  int y, w;
  cin >> y >> w;

  int m = max(w, y);

  int x = 6 - m +  1;

  int p = eu(x, 6);

  cout << x / p << '/' << 6 / p;
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