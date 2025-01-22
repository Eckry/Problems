#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  long long l, r;
  cin >> l >> r;
  if (r == l && l != 1)
    cout << 0 << "\n";
  else if (l == r && l == 1)
    cout << 1 << "\n";
  else
    cout << r - l << "\n";
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