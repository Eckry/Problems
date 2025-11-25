#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;
  ll x;
  cin >> x;
  ll mx = LONG_LONG_MIN;
  ll mn = LONG_LONG_MAX;
  for (int i = 0; i < n; i++) {
    mx = max(mx, a[i]);
    mn = min(mn, a[i]);
  }
  if (mn <= x && mx >= x) {
    cout << "YES" << "\n";
  } else
    cout << "NO" << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
