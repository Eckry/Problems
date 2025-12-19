#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;

  vector<pair<int, int>> seg;
  int start = -1;
  for (int i = 0; i < n; i++) {
    if (a[i] == k && start != -1) {
      seg.push_back({start, i - 1});
      start = -1;
    }
    if (a[i] != k && start == -1) {
      start = i;
    }
  }
  if (start != -1) {
    seg.push_back({start, n - 1});
  }
  int cnt = 0;
  vector<int> mex(n + 1, -1);

  int ans = 0;
  for (auto [l, r] : seg) {
    cnt = 0;
    for (int i = l; i <= r; i++) {
      if (mex[a[i]] != l && a[i] < k) {
        cnt++;
      }
      mex[a[i]] = l;
    }
    ans = max(ans, cnt);

    // cout << l << " " << r << "\n";
  }
  cout << k - ans + 1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
