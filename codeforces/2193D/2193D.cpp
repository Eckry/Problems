#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;
  vector<ll> b(n);
  for (auto &c : b)
    cin >> c;

  sort(a.begin(), a.end());

  vector<ll> pref(n, 0);
  pref[0] = b[0];
  for (int i = 1; i < n; i++) {
    pref[i] = pref[i - 1] + b[i];
  }
  int r = n - 1;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll s = n - i;
    ll x = a[i];
    while (r >= 0 && pref[r] > s) {
      r--;
    }
    ans = max(ans, x * (r + 1));
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
