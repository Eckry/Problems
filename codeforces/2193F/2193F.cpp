#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n, ax, ay, bx, by;
  cin >> n >> ax >> ay >> bx >> by;

  vector<ll> x(n);
  vector<ll> y(n);
  for (auto &c : x)
    cin >> c;
  for (auto &c : y)
    cin >> c;
  map<ll, pair<ll, ll>> mp;
  for (int i = 0; i < n; i++) {
    if (mp.find(x[i]) == mp.end()) {
      mp[x[i]].first = 0;
      mp[x[i]].second = 100000000000000LL;
    }
    mp[x[i]].first = max(mp[x[i]].first, y[i]);
    mp[x[i]].second = min(mp[x[i]].second, y[i]);
  }

  ll ans = bx - ax;
  ll up = ay;
  ll down = ay;
  ll bestdown = 0;
  ll bestup = 0;
  // cout << ans << "\n";

  for (auto [xi, par] : mp) {
    ll mx = par.first;
    ll mn = par.second;
    // cout << mx << " " << mn << "\n";

    ll sm = llabs(mx - mn);
    ll op1 = llabs(up - mx) + bestup;
    ll op2 = llabs(up - mn) + bestup;
    ll op3 = llabs(down - mn) + bestdown;
    ll op4 = llabs(down - mx) + bestdown;
    bestup = min(op2, op3) + sm;
    bestdown = min(op4, op1) + sm;
    down = mn;
    up = mx;
  }
  ans += min(bestup + llabs(up - by), bestdown + llabs(down - by));
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
