#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  if (n == 1 || n == 2) {
    cout << 1 << "\n";
    return;
  }
  vector<pair<int, int>> seg;
  vector<int> o;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      o.push_back(i);
      ans++;
    }
  }
  int m = o.size();
  if (m == 0) {
    cout << (n + 2) / 3 << "\n";
    return;
  }
  for (int i = 0; i < m - 1; i++) {
    int l = o[i] + 1;
    int r = o[i + 1] - 1;
    seg.push_back({l, r});
  }
  seg.push_back({0, o[0] - 1});
  seg.push_back({o[m - 1] + 1, n - 1});
  // cout << ans << "\n";
  for (auto [l, r] : seg) {
    if (l > r)
      continue;
    int acc = 0;
    if (l == 0)
      acc++;
    if (r == n - 1)
      acc++;
    ans += (r - l - 1 + acc + 2) / 3;
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
