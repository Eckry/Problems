#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<ll> a;
vector<ll> b;
vector<ll> uni;
map<ll, ll> mp;
ll m;
ll n;
ll check(ll mid) {
  if (mid > m) {
    return 0;
  }
  ll extra = 0;
  for (ll i = m - 1; i >= mid; i--) {
    extra += b[i];
  }
  ll j = 0;
  ll req = 0;
  for (ll i = mid - 1; i >= 0; i--) {
    ll num = uni[j];
    // cout << i << " i\n";
    req += mp[num];
    if (extra + b[i] < req)
      return 0;
    else if (b[i] < req) {
      extra -= req - b[i];
    } else {
      extra += b[i] - req;
    }
    // cout << extra << " extra\n";
    j++;
    if (extra < 0) {
      return 0;
    }
  }
  return 1;
}

void solve() {
  cin >> n >> m;
  a = vector<ll>(n);
  b = vector<ll>(m);
  uni = vector<ll>();
  mp = map<ll, ll>();
  for (auto &c : a)
    cin >> c;
  for (auto &c : b)
    cin >> c;

  sort(a.begin(), a.end(), greater<ll>());
  sort(b.begin(), b.end(), greater<ll>());

  ll seg = 0;
  vector<ll> aoe(n + 1);
  aoe[0] = 0;
  ll prev = -1;
  for (ll i = 0; i < n; i++) {
    if (a[i] != prev)
      seg++;
    aoe[seg] = i + 1;
    prev = a[i];
  }
  aoe[seg] = n;
  // for (ll i = 0; i <= n; i++) {
  //   cout << aoe[i] << " ";
  // }
  // cout << "\n";
  for (ll i = 0; i < n; i++) {
    if (mp.find(a[i]) == mp.end()) {
      uni.push_back(a[i]);
    }
    mp[a[i]]++;
  }
  ll l = 0;
  ll ans = 0;
  ll r = seg;
  while (l <= r) {
    ll mid = (l + r) >> 1;
    if (check(mid)) {
      l = mid + 1;
      ans = aoe[mid];
      // cout << mid << " yes\n";
    } else {
      r = mid - 1;
      // cout << mid << " no\n";
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  int i = 1;
  while (T--) {
    cout << "Case #" << i << ": ";
    i++;
    solve();
  }
}
