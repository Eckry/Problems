#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

ll MOD = 998244353;

void solve()
{
  ll w, h;
  cin >> w >> h;

  ll b = w + h;
  ll r = 1;
  ll a = 2;
  while (b)
  {
    if (b & 1)
    {
      r = (r * a) % MOD;
    }
    a = (a * a) % MOD;
    b >>= 1;
  }
  cout << r << "\n";
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