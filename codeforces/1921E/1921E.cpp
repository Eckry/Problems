#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll h, w, xa, ya, xb, yb;
  cin >> h >> w >> xa >> ya >> xb >> yb;

  if (xa >= xb) {
    cout << "Draw\n";
    return;
  }
  if ((xb - xa) & 1) {
    if (llabs(ya - yb) <= 1) {
      cout << "Alice\n";
      return;
    }
    if (ya < yb) {
      yb = w - yb + 1;
      ya = w - ya + 1;
    }
    ya -= yb - 1;
    xa += yb - 1;
    xb -= yb - 1;
    yb = 1;
    xb -= ya - 2;
    xa += ya - 1;
    ya = 1;
    if (xa <= xb) {
      cout << "Alice\n";
    } else {
      cout << "Draw\n";
    }
  } else {
    if (llabs(ya - yb) <= 0) {
      cout << "Bob\n";
      return;
    }
    if (ya > yb) {
      yb = w - yb + 1;
      ya = w - ya + 1;
    }
    yb -= ya - 1;
    xb -= ya - 1;
    xa += ya - 1;
    ya = 1;
    xa += yb - 1;
    xb -= yb - 1;
    yb = 1;
    if (xb >= xa) {
      cout << "Bob\n";
    } else {
      cout << "Draw\n";
    }
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
