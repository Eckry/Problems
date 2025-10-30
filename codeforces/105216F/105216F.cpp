#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n, p;
  cin >> n >> p;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] <= p) {
      ans = max(ans, a[i]);
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  T = 1;
  while (T--)
    solve();
}
