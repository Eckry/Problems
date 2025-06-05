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
  ll n, x;
  cin >> n >> x;
  ll bits = __builtin_popcountll(x);
  if (n <= bits)
  {
    cout << x << "\n";
    return;
  }
  if ((n - bits) % 2 == 0)
    cout << x + n - bits << "\n";
  else
  {
    if (x > 1)
    {
      cout << x + n - bits + 1 << "\n";
      return;
    }
    if (x == 1)
    {
      cout << n + 3 << "\n";
      return;
    }
    else
    {
      if (n == 1)
      {
        cout << -1 << "\n";
        return;
      }
      else
        cout << n + 3 << "\n";
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