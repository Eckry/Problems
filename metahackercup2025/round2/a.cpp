#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n, m;
  cin >> n >> m;
  if (m > n) {
    cout << "NO" << "\n";
    return;
  }
  if (m == n) {
    if (m == 1) {
      cout << "NO" << "\n";
      return;
    }
    cout << "YES" << "\n";
    return;
  }

  if (n < (m - 1) * 2) {
    cout << "YES" << "\n";
    return;
  }
  if (n & 1) {
    cout << "NO" << "\n";
    return;
  } else {
    cout << "YES\n";
    return;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  int i = 1;
  while (T--) {
    cout << "Case #" << i << ": ";
    i++;
    solve();
  }
}
