#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<ll> p(n);
  vector<ll> s(n);
  for (auto &c : p)
    cin >> c;
  for (auto &c : s)
    cin >> c;

  if (p[n - 1] != s[0]) {
    cout << "NO\n";
    return;
  }
  for (int i = 1; i < n; i++) {
    if (p[i - 1] % p[i] != 0) {
      cout << "NO\n";
      return;
    }
  }
  for (int i = n - 2; i >= 0; i--) {
    if (s[i + 1] % s[i] != 0) {
      cout << "NO\n";
      return;
    }
  }
  vector<ll> a(n);

  for (int i = 0; i < n; i++) {
    a[i] = lcm(p[i], s[i]);
  }
  ll g = 0;
  for (int i = 0; i < n; i++) {
    g = __gcd(a[i], g);
    if (g != p[i]) {
      cout << "NO\n";
      return;
    }
  }
  g = 0;
  for (int i = n - 1; i >= 0; i--) {
    g = __gcd(a[i], g);
    if (g != s[i]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES" << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
