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
  ll n, k;
  cin >> n >> k;

  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;
  vector<ll> faltan(64, 0);
  ll ans = 0;

  for (ll i = 0; i < n; i++)
  {
    ll p = a[i];
    ll cnt = 0;
    for (ll j = 0; j < 64; j++)
    {
      if (p & (1LL << j))
      {
        ans++;
      }
      else
      {
        faltan[j]++;
      }
    }
  }
  // cout << ans << "\n";
  // for (auto c : faltan)
  //   cout << c << " ";
  // cout << "\n";
  ll i = 0;
  while (i < 64 && k >= (1LL << i))
  {
    while (faltan[i] && k >= (1LL << i))
    {
      faltan[i]--;
      k -= (1LL << i);
      ans++;
    }
    i++;
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