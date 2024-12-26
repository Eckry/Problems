#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  long long int a1, a2, a3, a4;
  cin >> a1 >> a2 >> a3 >> a4;

  long long int sm = a1;
  long long int alice = a1 + 1;
  long long int bob = a1 + 1;

  if (a2 < a3)
  {
    if (alice == 1)
    {
      cout << sm + 1 << "\n";
      return;
    }
    sm += a2 * 2;
    a3 = a3 - a2;
    a2 = 0;

    if (alice - a3 <= 0)
    {
      cout << sm + alice << "\n";
      return;
    }
    alice -= a3;
    bob += a3;
    sm += a3;
  }
  else if (a2 > a3)
  {
    if (bob == 1)
    {
      cout << sm + 1 << "\n";
      return;
    }
    sm += a3 * 2;
    a2 = a2 - a3;
    a3 = 0;

    if (bob - a2 <= 0)
    {
      cout << sm + bob << "\n";
      return;
    }
    sm += a2;
    alice += a2;
    bob -= a2;
  }
  else
  {
    if (bob == 1)
    {
      cout << sm + 1 << "\n";
      return;
    }
    sm += a3 + a2;
    a3 = 0;
    a2 = 0;
  }

  long long int mn = min(bob, alice);
  cout << sm + min(mn, a4) << "\n";
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