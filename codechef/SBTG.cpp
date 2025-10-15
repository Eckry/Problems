#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n, x, k;
  cin >> n >> x >> k;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;

  sort(a.begin(), a.end(), greater<>());

  if (k != 0) {
    for (int i = 0; i < n; i++) {
      if (a[i] > x) {
        x += 100;
        a[i] = 0;
        k--;
      }
      if (k == 0) {
        break;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > x)
      ans++;
  }
  cout << ans + 1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
