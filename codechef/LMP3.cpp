#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  if (n & 1) {
    cout << 0 << "\n";
    return;
  }
  if (n < 10 && n % 2 == 0) {
    cout << -1 << "\n";
    return;
  }
  int temp = n;
  int prev = -1;
  int mx = 0;
  int first = -1;
  while (temp) {
    prev = temp % 10;
    if (first == -1)
      first = prev;
    mx = max(mx, prev);
    if (prev & 1) {
      cout << 1 << "\n";
      return;
    }
    temp /= 10;
  }
  if (mx == first) {
    cout << 3 << "\n";
  } else {
    cout << 2 << "\n";
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
