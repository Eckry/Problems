#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  int ans = 1;
  if (n & 1) {
    cout << 0 << "\n";
    return;
  }
  while (n >= 4) {
    n -= 4;
    ans++;
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
