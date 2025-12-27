#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n;
  cin >> n;
  map<ll, ll> minus;
  map<ll, ll> plus;
  map<ll, ll> h;
  map<ll, ll> v;

  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    ans += 2LL * minus[x + y];
    ans += 2LL * plus[y - x];
    ans += 2LL * h[y];
    ans += 2LL * v[x];
    minus[x + y]++;
    plus[y - x]++;
    h[y]++;
    v[x]++;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
