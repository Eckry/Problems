#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;

  vector<ll> pref(n);
  pref[0] = a[0];
  vector<ll> suf(n + 1, 0);
  for (int i = 1; i < n; i++) {
    pref[i] = max(pref[i - 1], a[i]);
  }
  for (int i = n - 1; i >= 0; i--) {
    suf[i] = suf[i + 1] + a[i];
  }
  for (int i = 0; i < n; i++) {
    cout << pref[n - 1 - i] + suf[n - i] << " ";
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
