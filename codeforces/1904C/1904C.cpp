#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;
  if (k >= 3) {
    cout << 0 << "\n";
  } else if (k == 1) {
    sort(a.begin(), a.end());
    ll ans = 1e18 + 111;
    for (int i = 0; i < n; i++) {
      ans = min(ans, a[i]);
      // cout << a[i] << " ";
    }
    // cout << "\n";
    for (int i = 1; i < n; i++) {
      ans = min(ans, a[i] - a[i - 1]);
    }
    cout << ans << "\n";
  } else {
    vector<ll> op;
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        op.push_back(llabs(a[j] - a[i]));
      }
    }
    int m = op.size();
    ll ans = 1e18 + 111;
    for (int i = 0; i < n; i++) {
      ans = min(ans, a[i]);
    }
    for (auto c : op) {
      ans = min(ans, c);
      ll idx = lower_bound(a.begin(), a.end(), c) - a.begin();
      ans = min(ans, llabs(a[idx] - c));
      if (idx) {
        ans = min(ans, llabs(a[idx - 1] - c));
      }
    }
    cout << ans << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
