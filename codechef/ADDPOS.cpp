#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;
  ll ans = 0;
  ll sm = 0;
  for (int i = 0; i < n; i++) {
    sm += a[i];
  }
  if (sm >= 0)
    cout << 0 << "\n";
  else
    cout << (llabs(sm) + n - 1) / n << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
