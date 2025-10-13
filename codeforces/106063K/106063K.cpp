#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                                                             \
  cin.tie(0);                                                                  \
  cin.sync_with_stdio(0);                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cout.tie(0);

void solve() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;

  if (b <= c) {
    cout << 0 << "\n";
    return;
  }
  if (d <= a) {
    cout << 0 << "\n";
    return;
  }
  if (a == c && b == d) {
    cout << b - a << "\n";
    return;
  }
  if (a <= c && b <= d) {
    cout << llabs(b - c) << "\n";
    return;
  }
  if (a <= c && d <= b) {
    cout << llabs(d - c) << "\n";
    return;
  }
  if (c <= a && d <= b) {
    cout << llabs(d - a) << "\n";
    return;
  }
  if (c <= a && b <= d) {
    cout << llabs(b - a) << "\n";
    return;
  }
  cout << 0 << "\n";
}

int main() {
  optimize();
  int T;
  cin >> T;
  while (T--)
    solve();
}
