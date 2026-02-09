#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n, x, y;
  cin >> n >> x >> y;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;
  ll sm = 0;
  for (int i = 0; i < n; i++) {
    sm += a[i] / x * y;
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, sm - a[i] / x * y + a[i]);
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
