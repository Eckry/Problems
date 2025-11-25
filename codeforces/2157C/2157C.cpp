#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> ans(n, -1);
  vector<pair<int, int>> c1;
  vector<pair<int, int>> c2;
  while (q--) {
    int c, l, r;
    cin >> c >> l >> r;
    l--;
    r--;
    if (c == 1) {
      c1.push_back({l, r});
    } else {
      c2.push_back({l, r});
    }
  }

  for (auto [l, r] : c1) {
    for (int i = l; i <= r; i++) {
      ans[i] = -2;
    }
  }
  for (auto [l, r] : c2) {
    for (int i = l; i <= r; i++) {
      if (ans[i] == -2)
        ans[i] = 10000;
    }
  }
  for (auto [l, r] : c1) {
    for (int i = l; i <= r; i++) {
      if (ans[i] == 10000) {
        continue;
      }
      ans[i] = k;
    }
  }
  int cnt = 1;
  sort(c2.begin(), c2.end(), [&](auto x, auto y) { return x.first < y.first; });
  for (auto [l, r] : c2) {
    vector<int> seen(k, 0);
    for (int i = l; i <= r; i++) {
      if (ans[i] != 10000 && ans[i] != -2 && ans[i] != -1) {
        seen[ans[i]]++;
      }
    }
    for (int i = l; i <= r; i++) {
      int mex = 0;
      if (ans[i] == -2 || ans[i] == -1) {
        while (mex < k && seen[mex])
          mex++;
        if (mex >= k)
          break;
        ans[i] = mex;
        seen[mex]++;
      }
    }
    cnt++;
  }
  for (int i = 0; i < n; i++) {
    if (ans[i] == -1 || ans[i] == -2) {
      ans[i] = 10000;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
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
