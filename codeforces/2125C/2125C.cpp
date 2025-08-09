#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                                                             \
  cin.tie(0);                                                                  \
  cin.sync_with_stdio(0);                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cout.tie(0);

void solve() {
  ll l, r;
  cin >> l >> r;
  // 2, 3, 5, 7
  ll p = 210;
  for (int i = 0; i < 210; i++) {
    if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0 || i % 7 == 0) {
      p--;
    }
  }
  ll left = (l - 1) / 210;
  ll right = r / 210;
  ll ans = p * right - p * left;
  ll remainderleft = (l - 1) % 210;
  ll secondleft = remainderleft;
  for (ll i = 0; i <= remainderleft; i++) {
    if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0 || i % 7 == 0) {
      secondleft--;
    }
  }
  ll remainderright = r % 210;
  ll secondright = remainderright;
  for (ll i = 0; i <= remainderright; i++) {
    if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0 || i % 7 == 0) {
      secondright--;
    }
  }
  ans -= secondleft;
  ans += secondright;
  cout << ans << "\n";
}

int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
}
