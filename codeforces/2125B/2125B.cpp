#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                                                             \
  cin.tie(0);                                                                  \
  cin.sync_with_stdio(0);                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cout.tie(0);

void solve() {
  ll a, b, k;
  cin >> a >> b >> k;
  if ((k >= a && k >= b) || a == b) {
    cout << 1 << "\n";
    return;
  }
  if (max(a, b) % min(a, b) == 0) {
    ll p = max(a, b) / min(a, b);
    if (p <= k) {
      cout << 1 << "\n";
      return;
    }
  }

  ll ans = 0;
  ll gcd = __gcd(a, b);
  ll num = max(a, b) / gcd;
  if (gcd != 1LL && num <= k) {
    cout << 1 << "\n";
    return;
  }

  cout << 2 << "\n";
}

int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
}
