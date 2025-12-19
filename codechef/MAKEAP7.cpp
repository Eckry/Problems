#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;

  ll g = 0;
  for (int i = 0; i < n - 1; i++) {
    g = __gcd(g, a[i + 1] - a[i]);
  }
  ll ans = 0;
  for (int i = 0; i < n - 1; i++) {
    ll diff = a[i + 1] - a[i];
    if (diff != g) {
      ans += diff / g - 1;
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
