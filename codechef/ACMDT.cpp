#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll b, g, x, y, n;
  cin >> b >> g >> x >> y >> n;
  if (x + y > n) {
    cout << -1 << "\n";
    return;
  }

  if (g > b) {
    swap(g, b);
    swap(x, y);
  }
  ll ans = (g + b + n - 1) / n;
  if (ans * y > g || ans * x > b) {
    cout << -1 << "\n";
    return;
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
