#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll x, y;
  cin >> x >> y;

  if (y < 0) {
    y = -y;
    if (4 * y > x) {
      cout << "NO\n";
      return;
    }
    if ((x - 4 * y) % 3 != 0) {
      cout << "NO\n";
      return;
    }
    cout << "YES\n";
  } else if (y > 0) {
    if (2 * y > x) {
      cout << "NO\n";
      return;
    }
    if ((x - 2 * y) % 3 != 0) {
      cout << "NO\n";
      return;
    }
    cout << "YES\n";
  } else {
    if (x % 3 == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
