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
  ll n;
  cin >> n;

  vector<ll> divisors;
  ll cnt = 0;
  ll ans = 1;
  ll end = 0;
  for (ll i = 2; i <= 1e6; i++)
  {
    if (n % i == 0)
    {
      ans++;
    }
    else
    {
      break;
    }
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