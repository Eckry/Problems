#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;
  vector<ll> pref(n + 1, 0);
  vector<ll> suf(n + 1, 0);
  for (ll i = 0; i < n; i++) {
    pref[i + 1] = pref[i] + a[i];
  }
  for (ll i = n - 1; i >= 0; i--) {
    suf[i] = suf[i + 1] + a[i];
  }
  vector<ll> maxr(n + 1, 0);
  for (ll i = n - 1; i >= 0; i--) {
    maxr[i] = max(maxr[i + 1], (i + 1) * (i + 1) + i + 1 + suf[i + 1]);
  }
  vector<ll> ans(n);
  for (ll i = 0; i < n; i++) {
    ans[i] = pref[i] - (i + 1) * (i + 1) + i + 1 + maxr[i];
  }
  ll res = accumulate(a.begin(), a.end(), 0);

  for (ll i = 0; i < n; i++) {
    res = max(res, ans[i]);
  }
  cout << res << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
