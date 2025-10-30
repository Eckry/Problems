#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {

  ll n, t;
  cin >> n >> t;

  t--;
  if (t == 0) {
    cout << n << "\n";
    return;
  }
  ll ans = 1;
  if (n >= t && t != 1)
    ans++;
  for (ll i = 2; i * i <= t && i <= n; i++) {
    if (t % i == 0) {
      if (i * i == t)
        ans++;
      else {
        if (t / i <= n) {
          ans += 2;
        } else
          ans++;
      }
    }
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
