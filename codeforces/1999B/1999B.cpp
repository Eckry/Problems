#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int a1, a2, b1, b2;

  cin >> a1 >> a2 >> b1 >> b2;
  int ans = 0;
  if (a1 == b1)
  {
    if (a2 > b2)
      ans++;
  }
  else if (a1 > b1)
  {
    if (a2 >= b2)
      ans++;
  }

  if (a1 == b2)
  {
    if (a2 > b1)
      ans++;
  }
  else if (a1 > b2)
  {
    if (a2 >= b1)
      ans++;
  }

  if (a2 == b1)
  {
    if (a1 > b2)
      ans++;
  }
  else if (a2 > b1)
  {
    if (a1 >= b2)
      ans++;
  }

  if (a2 == b2)
  {
    if (a1 > b1)
      ans++;
  }
  else if (a2 > b2)
  {
    if (a1 >= b1)
      ans++;
  }

  cout << ans << "\n";
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