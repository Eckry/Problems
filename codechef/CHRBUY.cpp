#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int w, p, k;
  cin >> w >> p >> k;
  if (k <= w) {
    cout << k * 2 << "\n";
  } else {
    cout << w * 2 + (k - w) << "\n";
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
