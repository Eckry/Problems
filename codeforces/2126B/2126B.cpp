#include <bits/stdc++.h>

using namespace std;

void solve() {

  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;
  int cnt = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0)
      cnt++;
    if (a[i] == 1)
      cnt = 0;
    if (cnt == k) {
      cnt = 0;
      ans++;
      i++;
    }
  }
  cout << ans << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
