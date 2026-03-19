#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll p, q;
  cin >> p >> q;

  if (3LL * p <= 2LL * q + (p + q - 1) / 2 && 3LL * p >= 2LL * q) {
    cout << "Bob\n";
  } else {
    cout << "Alice\n";
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
