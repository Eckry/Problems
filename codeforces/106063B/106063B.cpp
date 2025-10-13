#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                                                             \
  cin.tie(0);                                                                  \
  cin.sync_with_stdio(0);                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cout.tie(0);

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;
  vector<ll> inc(n, 0);
  for (ll i = 0; i < (n + 1) / 2; i++) {
    inc[i] = i + 1;
  }
  vector<ll> seq(n, 0);
  for (ll i = 0; i < (n + 1) / 2; i++) {
    seq[i] = n - i;
  }
  for (ll i = 0; i < n; i++) {
    inc[n - 1 - i] = inc[i];
    seq[n - 1 - i] = seq[i];
  }
  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    ans += seq[i] * inc[i] * a[i];
  }
  cout << ans << "\n";
}

int main() {
  optimize();
  int T;
  T = 1;
  while (T--)
    solve();
}
