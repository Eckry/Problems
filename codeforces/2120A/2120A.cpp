#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int l1, b1, l2, b2, l3, b3;
  cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
  if (l1 == b1) {
    cout << "NO\n";
    return;
  }

  if (b1 == b2 + b3 && b1 == l1 + l2 && b1 == l3 + l1) {
    cout << "YES\n";
    return;
  }
  if (b1 == b2 && b1 == b3 && b1 == l1 + l2 + l3) {
    cout << "YES\n";
    return;
  }
  if (l1 == l2 + l3 && l1 == b1 + b2 && l1 == b3 + b1) {
    cout << "YES\n";
    return;
  }
  if (l1 == l2 && l1 == l3 && l1 == b1 + b2 + b3) {
    cout << "YES\n";
    return;
  }
  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
