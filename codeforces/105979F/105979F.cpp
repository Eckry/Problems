#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  ll mx = 0;
  ll sma = 0;
  ll smb = 0;
  for (int i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    mx = max(mx, a + b);
    sma += a;
    smb += b;
  }
  ll sm = sma + smb;
  ll ans = llabs(sma - smb);
  ans = max(ans, 2 * mx - sm);
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
