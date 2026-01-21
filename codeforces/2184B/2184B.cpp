#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll s, k, m;
  cin >> s >> k >> m;

  if (k > s) {
    // if (k > m) {
    //   cout << 0 << "\n";
    //   return;
    // }
    ll d = m / k;
    cout << max(s - llabs(m - k * d), 0LL) << "\n";
    return;
  }
  ll d = m / k;
  if (d & 1) {
    cout << k - llabs(k * d - m) << "\n";
  } else {
    cout << s - llabs(m - k * d) << "\n";
  }
}

int main() {
  // for (int i = 1; i < 15; i++) {
  //   for (int j = 1; j < 15; j++) {
  //     for (int k = 1; k < 15; k++) {
  //       cout << i << " " << j << " " << k << "\n";
  //     }
  //   }
  // }
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
