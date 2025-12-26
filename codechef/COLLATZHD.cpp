#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n;
  cin >> n;
  int ans = 0;

  if (n == 1) {
    cout << "0\n";
    return;
  }

  if (n == 3 || n == 2) {
    cout << 1 << "\n";
    return;
  }

  if (!(1LL & n) && !(2LL & n)) {
    // map<ll, ll> vis;
    // vis[n] = 1;
    while (n != 1) {
      // cout << n << " -> ";
      if (__popcount((unsigned long long)n) == 2) {
        ll bit = 63 - __countl_zero((unsigned long long)n);
        // cout << bit << " " << n << "\n";
        if ((n & (1LL << bit)) && (n & (1LL << (bit - 1)))) {
          ans += bit;
          break;
        }
      }
      if (__popcount((unsigned long long)n) == 1LL || !(4LL & n)) {
        n >>= 1;
        ans++;
      } else {
        n = (n ^ 3LL) + 1LL;
        ans++;
      }
      // if (vis.find(n) != vis.end()) {
      //   cout << -1 << "\n";
      //   return;
      // }
      // vis[n] = 1;
      // cout << n << "\n";
      // cout << n << "\n";
    }
    cout << ans << "\n";
    return;
  }

  while (n % 2 == 0) {
    n >>= 1;
    ans++;
  }

  if (n == 1) {
    cout << ans + 1 << "\n";
    return;
  }

  if (n == 3 || n == 2) {
    cout << ans + 1 << "\n";
    return;
  }

  cout << "-1\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
