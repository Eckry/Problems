#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;

  vector<ll> suf(n + 1, 0);
  for (int i = n - 1; i >= 0; i--) {
    suf[i] = suf[i + 1] - a[i];
  }
  ll ans = -1000000000000000000LL;
  ll sm = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, sm + suf[i + 1]);
    if (!i)
      sm += a[i];
    else
      sm += llabs(a[i]);
  }
  for (int i = 0; i < n; i++) {
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
