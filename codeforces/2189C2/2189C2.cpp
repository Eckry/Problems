#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;

  if (n & 1) {
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      ans[i] = (i + 1) ^ 1;
    }
    ans[n - 1] = 1;
    ans[0] = n - 1;
    for (auto c : ans) {
      cout << c << " ";
    }
    cout << "\n";
    return;
  }

  if (__builtin_popcount(n) == 1) {
    cout << -1 << "\n";
    return;
  }
  vector<int> ans(n);
  int x = n ^ (1 << (31 - __builtin_clz(n)));
  int pos = 0;
  for (int i = 0; i < n; i++) {
    ans[i] = (i + 1) ^ 1;
    if (x == ((i + 1) ^ 1)) {
      pos = i;
    }
  }
  ans[0] = n;
  ans[n - 1] = 1;
  swap(ans[pos], ans[0]);
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
