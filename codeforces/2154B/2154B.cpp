#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;
  vector<int> mx(n, 0);
  mx[0] = a[0];
  for (int i = 1; i < n; i++) {
    mx[i] = max(mx[i - 1], a[i]);
  }

  for (int i = 0; i < n; i++) {
    if (i & 1) {
      a[i] = mx[i];
    }
  }
  int ans = 0;
  // for (auto c : a) {
  //   cout << c << " ";
  // }
  // cout << "\n";
  for (int i = 1; i < n; i += 2) {
    if (i == n - 1 && a[i - 1] >= a[i]) {
      ans += a[i - 1] - a[i] + 1;
      a[i - 1] = a[i] - 1;
    }
    if (i && i != n - 1 && a[i - 1] >= a[i]) {
      ans += a[i - 1] - a[i] + 1;
      a[i - 1] = a[i] - 1;
    }
    if (i && i != n - 1 && a[i + 1] >= a[i]) {
      ans += a[i + 1] - a[i] + 1;
      a[i + 1] = a[i] - 1;
    }
  }
  // for (auto c : a) {
  //   cout << c << " ";
  // }
  // cout << "\n";
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
