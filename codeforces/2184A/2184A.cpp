#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  if (n == 2) {
    cout << 2 << "\n";
    return;
  }
  if (n == 3) {
    cout << 3 << "\n";
    return;
  }
  while (n > 3) {
    n -= 4;
  }
  if (n == 0) {
    cout << 0 << "\n";
    return;
  }
  if (n == 1) {
    cout << 1 << "\n";
    return;
  }
  if (n == 2) {
    cout << 0 << "\n";
    return;
  }
  if (n == 3) {
    cout << 1 << "\n";
    return;
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
