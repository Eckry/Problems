#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                                                             \
  cin.tie(0);                                                                  \
  cin.sync_with_stdio(0);                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cout.tie(0);

void solve() {
  ll x, y;
  cin >> x >> y;
  if (x == y || y == 1) {
    cout << -1 << "\n";
    return;
  }
  if (x < y) {
    cout << 2 << "\n";
    return;
  }
  if (x - 1 > y) {
    cout << 3 << "\n";
    return;
  }
  cout << -1 << "\n";
}

int main() {
  optimize();
  int T;
  cin >> T;
  while (T--)
    solve();
}
