#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll e(ll a, ll b) {
  if (b < 0) {
    return 0;
  }
  ll res = 1;
  while (b) {
    if (b & 1) {
      res = res * a;
    }
    a = a * a;
    b >>= 1;
  }
  return res;
}

void solve() {
  ll n;
  cin >> n;
  ll ans = 0;
  int i = 0;
  while (n) {
    ans += (n % 3) * (e(3, i + 1) + i * e(3, i - 1));
    i++;
    n /= 3;
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
