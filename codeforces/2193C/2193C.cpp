#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n, q;
  cin >> n >> q;
  vector<ll> a(n);
  vector<ll> b(n);
  for (auto &c : a)
    cin >> c;
  for (auto &c : b)
    cin >> c;

  ll mx = max(a[n - 1], b[n - 1]);
  a[n - 1] = mx;
  for (int i = n - 2; i >= 0; i--) {
    mx = max(a[i], mx);
    mx = max(b[i], mx);
    a[i] = mx;
  }
  vector<ll> pref(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + a[i - 1];
  }
  while (q--) {
    ll l, r;
    cin >> l >> r;
    cout << pref[r] - pref[l - 1] << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
