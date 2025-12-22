#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;
  if (n == 1) {
    cout << 0 << "\n";
    return;
  }

  ll g = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == a[n - 1 - i])
      continue;
    if (a[i] < a[n - 1 - i])
      swap(a[i], a[n - 1 - i]);
    g = __gcd(g, a[i] - a[n - 1 - i]);
  }
  cout << g << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
