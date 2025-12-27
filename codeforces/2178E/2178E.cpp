#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll ask(int l, int r) {
  cout << "? " << l << " " << r << endl;
  ll x;
  cin >> x;
  return x;
}

void solve() {
  ll n;
  cin >> n;
  ll l = 1;
  ll r = n;
  ll total = ask(l, r);
  ll ans = total;
  total >>= 1;
  while (l != r) {
    ll lo = l;
    ll hi = r;
    while (lo < hi) {
      ll mid = (lo + hi) >> 1;
      ll res = ask(l, mid);
      if (res == total) {
        ans = res;
        total >>= 1;
        if (mid - l > r - mid - 1) {
          l = mid + 1;
        } else {
          r = mid;
        }
        break;
      }
      if (res < total) {
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }
  }
  cout << "! " << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
