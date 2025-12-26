#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int l, a, b;
  cin >> l >> a >> b;
  int pos = a;
  int ans = 0;
  for (int i = 0; i <= l; i++) {
    ans = max(ans, pos);
    pos = (pos + b) % l;
    ans = max(ans, pos);
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
