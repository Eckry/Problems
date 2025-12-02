#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll x, y, k;

int check(ll m) {
  ll temp = x;
  ll p = m - 1;
  while (p > 0 && temp--) {
    p -= p / y;
  }
  if (p < k) {
    return 1;
  } else {
    return 0;
  }
}

void solve() {
  cin >> x >> y >> k;
  ll l = 1;
  ll r = 1e12 + 1;
  while (l <= r) {
    ll m = l + ((r - l) >> 1);
    int res = check(m);
    if (res) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  if (r == 1e12 + 1)
    cout << -1 << "\n";
  else
    cout << r << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
