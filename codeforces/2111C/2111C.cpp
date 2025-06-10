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
  vector<ll> a;
  ll y;
  cin >> y;
  a.push_back(y);
  for (ll i = 0; i < n - 1; i++)
  {
    ll x;
    cin >> x;
    a.push_back(x);
  }

  ll ans = LONG_LONG_MAX;
  for (ll i = 0; i < n; i++)
  {
    ll j = i;
    while(j < n && a[j] == a[i]) j++;
    if(j == n) {
      ans = min(ans, a[i] * i);
    } else {
      ans = min(ans, a[i] * i + a[i] * (n - j));
    }
    i = j - 1;
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