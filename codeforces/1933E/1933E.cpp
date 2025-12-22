#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;
  vector<ll> pref(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + a[i - 1];
  }
  int q;
  cin >> q;
  while (q--) {
    int l, u;
    cin >> l >> u;
    u += pref[l - 1];
    int r = lower_bound(pref.begin() + l, pref.end(), u) - pref.begin();
    if (r >= n + 1)
      r--;

    u -= pref[r - 1];
    if (r != l && u * 2 < pref[r] - pref[r - 1]) {
      r--;
    }

    cout << r << " ";
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
