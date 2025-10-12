#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                                                             \
  cin.tie(0);                                                                  \
  cin.sync_with_stdio(0);                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cout.tie(0);

ll nck(ll n, ll k) {
  if (k == 3)
    return n * (n - 1) * (n - 2) / 6LL;
  return n * (n - 1) * (n - 2) * (n - 3) / 24LL;
}

// n! / (n - k)!k!

void solve() {
  int n;
  cin >> n;
  vector<pair<ll, ll>> a(n);
  for (auto &c : a)
    cin >> c.first >> c.second;
  map<tuple<ll, ll, ll>, set<ll>> mp;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      ll A = a[j].second - a[i].second;
      ll B = a[i].first - a[j].first;
      ll C = A * a[i].first + B * a[i].second;

      ll gcd = __gcd(llabs(A), llabs(B));
      gcd = __gcd(gcd, llabs(C));

      A /= gcd;
      B /= gcd;
      C /= gcd;

      if (A < 0 || (A == 0 && B < 0)) {
        A = -A;
        B = -B;
        C = -C;
      }
      mp[{A, B, C}].insert(i);
      mp[{A, B, C}].insert(j);
    }
  }
  ll ans = 0;
  ans += nck(n, 4);

  for (auto line : mp) {
    ll k = line.second.size();
    if (k >= 3) {
      ans -= nck(k, 4) + nck(k, 3) * (n - k);
    }
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
