#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n, x;
  cin >> n >> x;

  ll ans = 0;
  for (ll a = 1; a <= min(n, x); a++) {
    ll b = 1;
    while (a + b <= x && b * a <= n) {
      ans += min(x - a - b, (n - a * b) / (a + b));
      b++;
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
