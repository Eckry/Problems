#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n, l, r;
  cin >> n >> l >> r;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;
  ll sm = 0;
  ll ans = 0;
  int i = 0, j = 0;
  while (j < n) {
    while (j < n && sm < l) {
      sm += a[j];
      j++;
    }
    if (l <= sm && sm <= r) {
      i = j;
      sm = 0;
      ans++;
      continue;
    }
    sm -= a[i];
    i++;
  }
  while (i < n) {
    if (l <= sm && sm <= r) {
      ans++;
      break;
    }
    sm -= a[i];
    i++;
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
