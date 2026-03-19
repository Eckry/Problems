#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll x;
  cin >> x;
  int ans = 0;
  for (ll i = x; i <= x + 1000; i++) {
    ll temp = i;
    ll sm = 0;
    while (temp) {
      sm += temp % 10;
      temp /= 10;
    }
    if (i - sm == x)
      ans++;
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
