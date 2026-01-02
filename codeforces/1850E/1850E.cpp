#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<ll> sq(1000000);

void solve() {
  ll n, c;
  cin >> n >> c;
  vector<ll> a(n);
  for (auto &it : a)
    cin >> it;

  ll l = 1;
  ll r = 1e9 + 100;
  ll ans = 1;
  while (l <= r) {
    ll m = l + (r - l) / 2;
    ll sm = 0;
    for (ll i = 0; i < n; i++) {
      sm = sm + (a[i] + 2LL * m) * (a[i] + 2LL * m);
      if (sm > c) {
        break;
      }
    }
    // cout << sm << "\n";

    if (sm <= c) {
      l = m + 1;
      ans = m;
    } else {
      r = m - 1;
    }
  }
  cout << ans << "\n";
}

int main() {
  for (ll i = 0; i * i <= 1000000; i++) {
    sq[i * i] = i;
  }
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
