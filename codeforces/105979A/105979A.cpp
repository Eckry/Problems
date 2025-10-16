#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int ans = 0;
  int l, r, k;
  cin >> l >> r >> k;
  for (int i = l; i <= r; i++) {
    if (i % k == 0)
      ans++;
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
