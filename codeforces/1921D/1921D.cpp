#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;
  vector<ll> b(m);
  for (auto &c : b)
    cin >> c;

  sort(a.begin(), a.end());
  sort(b.begin(), b.end(), greater<ll>());
  ll d = 0;
  for (int i = 0; i < n; i++) {
    d += llabs(a[i] - b[i]);
  }
  ll ans = d;

  for (int i = 1; i <= n; i++) {
    d -= llabs(a[n - i] - b[n - i]);
    d += llabs(a[n - i] - b[m - i]);
    ans = max(ans, d);
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
