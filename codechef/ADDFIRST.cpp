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

  vector<pair<ll, ll>> pref(n + 1, {0, 0});
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1];
    if (a[i - 1] > pref[i - 1].first) {
      pref[i].first = a[i - 1];
      pref[i].second = i - 1;
    }
  }
  // for (int i = 0; i <= n; i++) {
  //   cout << pref[i].first << " ";
  // }
  // cout << "\n";
  // for (int i = 0; i <= n; i++) {
  //   cout << pref[i].second << " ";
  // }
  // cout << "\n";
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == b[i])
      continue;
    if (a[i] > b[i] || pref[i + 1].second != i) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
