#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll check(vector<ll> &a, ll m, ll k) {
  ll n = a.size();
  for (int i = 0; i < n; i++) {
    k -= max(0LL, m - a[i]);
    if (k < 0)
      return 0;
  }
  return 1;
}

void solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;

  ll l = 1, r = 1e12;
  ll seg = 0;
  while (l <= r) {
    ll m = l + (r - l) / 2;
    if (check(a, m, k)) {
      seg = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  ll ans = seg * n + 1;
  for (int i = 0; i < n; i++) {
    k -= max(0LL, seg - a[i]);
    a[i] = max(seg, a[i]);
  }

  for (int i = 0; i < n; i++) {
    ans -= (a[i] == seg);
  }
  cout << ans + k << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
