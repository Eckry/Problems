#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n, l, r;
  cin >> n >> l >> r;
  vector<ll> a(n);

  for (auto &c : a)
    cin >> c;
  sort(a.begin(), a.end());
  ll ans = 0;
  for (int i = 0, j = n - 1; i < n; i++, j--) {
    int lo = min(r, a[i]);
    int hi = max(l, a[j]);
    if (lo >= hi) {
      break;
    }
    ans += hi - lo;
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
