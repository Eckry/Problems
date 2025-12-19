#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  vector<ll> b(n);
  for (auto &c : a)
    cin >> c;
  for (auto &c : b)
    cin >> c;

  vector<ll> pref(n, 0);
  pref[0] = b[0];
  for (int i = 1; i < n; i++) {
    pref[i] = pref[i - 1] + b[i];
  }

  ll mxi = -1;
  ll idx = -1;

  for (int i = 0; i < n; i++) {
    if (pref[i] < a[i] && a[i] - pref[i] > mxi) {
      mxi = a[i] - pref[i];
      idx = i;
    }
  }
  // cout << idx << " \n";
  // cout << mxi << "\n";
  if (idx == -1) {
    cout << (m)*pref[n - 1] + m * (m + 1) / 2 << "\n";
    return;
  }
  if (m < mxi) {
    cout << (m) * (pref[n - 1] - pref[idx] + a[idx]) << "\n";
    return;
  }

  ll ans = 0;
  ans += (mxi) * (pref[n - 1] - pref[idx] + a[idx]);
  // cout << pref[n - 1] << " " << pref[idx] << " " << a[idx] << "\n";
  // cout << ans << "\n";
  ans += (m * (m + 1) / 2 - mxi * (mxi + 1) / 2) + (m - mxi) * (pref[n - 1]);
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
