#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n, m;
  cin >> n >> m;
  map<ll, ll> mp;
  for (int i = 0; i < n; i++) {
    int l;
    cin >> l;
    int mex = 0;
    map<int, int> cnt;
    for (int j = 0; j < l; j++) {
      int x;
      cin >> x;
      if (cnt.find(x) == cnt.end()) {
        cnt[x]++;
      }
    }
    int flg = 0;
    if (cnt.find(0) == cnt.end()) {
      flg = 1;
      mex++;
    }
    while (cnt.find(mex) != cnt.end()) {
      mex++;
      if (cnt.find(mex) == cnt.end() && !flg) {
        flg = 1;
        mex++;
      }
    }
    mp[mex]++;
  }
  ll mx = 0;
  for (auto [mex, val] : mp) {
    mx = max(mx, mex);
  }
  ll ans = 0;
  for (int i = 0; i <= min(mx, m); i++) {
    ans += mx;
  }
  if (m > mx) {
    ans += (m * (m + 1)) / 2 - (mx * (mx + 1)) / 2;
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
