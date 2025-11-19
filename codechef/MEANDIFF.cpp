#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;

  sort(a.begin(), a.end());

  ll ans = 0;
  ll sm = a[n - 1];
  ll div = 1;
  for (ll i = 0; i < n - 1; i++) {
    sm += a[i];
    div++;
    ll avg = sm / (div);
    // cout << sm << " " << avg << " avg\n";
    ans = max(ans, abs(avg - a[n - 1]));
  }
  sm = a[0];
  div = 1;
  for (ll i = n - 1; i > 0; i--) {
    sm += a[i];
    div++;
    ll avg = sm / (div);
    // cout << sm << " " << avg << " 2avg\n";
    ans = max(ans, abs(avg - a[0]));
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
