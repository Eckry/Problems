#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  ll ans = 0;
  while (n) {
    if (n <= 2)
      break;
    if (n % 3 == 0) {
      ans += n / 3;
      n /= 3;
    } else if (n % 3 == 1) {
      ans += n / 3;
      n = n / 3 + 1;
    } else {
      ans += n / 3;
      n = n / 3 + 2;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
