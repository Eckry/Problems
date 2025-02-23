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
  ll a, b, c, d;
  cin >> a >> b >> c >> d;

  for (ll x = a + 1; x <= c; x++)
  {
    ll t = a * b / __gcd(a * b, x);
    ll y = d / t;
    y *= t;
    if (y <= b)
      continue;
    cout << x << " " << y << "\n";
    return;
  }
  cout << -1 << " " << -1 << "\n";
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