#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;

  ll sm = 0;
  int e = 0;
  int o = 0;
  for (int i = 0; i < n; i++) {
    sm += a[i];
    if (a[i] & 1)
      o++;
    else
      e++;
    ll m = o % 3;
    if (!i) {
      cout << sm << " ";
      continue;
    }
    if (m == 0) {
      cout << sm - o / 3 << " ";
    } else if (m == 1) {
      cout << sm - (o + 2) / 3 << " ";
    } else if (m == 2) {
      cout << sm - o / 3 << " ";
    }
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
