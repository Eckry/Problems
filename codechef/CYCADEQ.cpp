#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n, c;
  cin >> n >> c;
  vector<ll> b(n);
  vector<ll> d(n);
  for (auto &it : b)
    cin >> it;
  for (auto &it : d)
    cin >> it;

  // ll mn = 1;
  // ll mnval = LONG_LONG_MAX;
  // for (int i = 1; i < n; i++) {
  //   if (mnval < (n - i) * b[i]) {
  //     mn = i;
  //     mnval = (n - i) * c + b[i] * d[0];
  //   }
  // }
  // vector<ll> ans(n, LONG_LONG_MAX);
  // int idx2 = 0;
  // if (mnval < b[0] * d[0]) {
  //   idx2 = mn;
  // } else {
  //   idx2 = 0;
  // }
  // ans[0] = idx2;
  // ll mxdis = 0;
  // for (int i = 1; i < n; i++) {
  //   ll dis;
  //   ll newvalue;
  //   ll newcalc;
  //   ll idx;
  //   if (i >= mn) {
  //     dis = i - mn;
  //     newcalc = dis * c + b[mn] * d[i];
  //     newvalue = c + b[i - 1] * d[i];
  //   } else {
  //     dis = n - (mn - i);
  //     newcalc = dis * c + b[mn] * d[i];
  //     newvalue = c + b[i - 1] * d[i];
  //   }
  //   if (newvalue < newcalc) {
  //     mn = i - 1;
  //   }
  //   ll newoption = b[i] * d[i];
  //   if (newoption <= newcalc && newoption <= newvalue) {
  //     idx = i;
  //   } else if (newvalue <= newcalc) {
  //     idx = i - 1;
  //     mxdis = max(mxdis, 1LL);
  //   } else {
  //     idx = mn;
  //     mxdis = max(mxdis, dis);
  //   }
  //   newcalc = min(newoption, newcalc);
  //   newvalue = min(newcalc, newvalue);
  //   if (newvalue == 0) {
  //     ans[i] = -1;
  //   } else
  //     ans[i] = idx;
  // }
  ll res1 = LONG_LONG_MAX;
  vector<ll> ans(n, LONG_LONG_MAX);
  for (int i = 0; i < n; i++) {
    ll res = c * i;
    for (int j = 0; j < n; j++) {
      ans[j] = min(ans[j], d[j] * b[(j - i + n) % n]);
    }
    for (int j = 0; j < n; j++) {
      res += ans[j];
    }
    res1 = min(res1, res);
  }
  cout << res1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
