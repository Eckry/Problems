#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll a, b, n;
  cin >> a >> b >> n;
  double x = (double)a / (double)n;
  if (x >= b) {
    cout << "1\n";
    return;
  } else {
    if (a == b) {
      cout << "1\n";
    } else
      cout << "2\n";
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
