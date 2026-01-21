#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll x, y, z, k;
  cin >> x >> y >> z >> k;
  ll ans = 0;
  for (ll a = 1; a <= x; a++) {
    for (ll b = 1; b <= y; b++) {
      if (k % (a * b) != 0)
        continue;
      ll c = k / (a * b);
      if (c > z)
        continue;
      ans = max(ans, (x - a + 1) * (y - b + 1) * (z - c + 1));
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
