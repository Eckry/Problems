#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int k;
  cin >> k;
  vector<ll> a(k);
  for (auto &c : a)
    cin >> c;
  int n;
  cin >> n;
  vector<vector<ll>> ing(n, vector<ll>(k));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      cin >> ing[i][j];
    }
  }
  ll day = LONG_LONG_MAX;
  ll order = LONG_LONG_MAX;
  for (int i = 0; i < k; i++) {
    vector<ll> pref(n + 1, 0);
    int flg = 0;
    for (int j = 1; j <= n; j++) {
      pref[j] = pref[j - 1] + ing[j - 1][i];
      if (pref[j] > a[i]) {
        if (day == 1 && order > j) {
          order = j;
        }
        if (day > 1) {
          order = j;
          day = 1;
        }
        flg = 1;
        break;
      }
    }
    if (pref[n] == 0 || flg)
      continue;
    // cout << pref[n] << " pref\n";
    ll newday = a[i] / pref[n];
    ll truenewday = (a[i] + pref[n] - 1) / pref[n];
    if (a[i] % pref[n] == 0) {
      truenewday++;
    }
    a[i] -= newday * pref[n];
    ll idx;
    for (int j = 1; j <= n; j++) {
      if (pref[j] > a[i]) {
        idx = j;
        break;
      }
    }
    // cout << idx << " " << i << "\n";
    if (truenewday == day && order > idx) {
      order = idx;
    }
    if (truenewday < day) {
      day = truenewday;
      order = idx;
    }
  }
  cout << day << " " << order << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  T = 1;
  while (T--)
    solve();
}
