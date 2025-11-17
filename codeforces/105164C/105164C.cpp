#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll L, W, H;
  cin >> L >> W >> H;
  ll l, w, h;
  cin >> l >> w >> h;

  ll x = L / l;
  ll y = W / w;
  ll z = H / h;
  ll ans = x * y * z;
  x = L / l;
  y = W / h;
  z = H / w;
  ans = max(ans, x * y * z);
  x = L / h;
  y = W / w;
  z = H / l;
  ans = max(ans, x * y * z);
  x = L / h;
  y = W / l;
  z = H / w;
  ans = max(ans, x * y * z);
  x = L / w;
  y = W / h;
  z = H / l;
  ans = max(ans, x * y * z);
  x = L / w;
  y = W / l;
  z = H / h;
  ans = max(ans, x * y * z);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  T = 1;
  while (T--)
    solve();
}
