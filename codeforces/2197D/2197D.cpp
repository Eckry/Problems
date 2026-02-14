#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] * a[i] >= n) {
      for (int j = 1; i + a[i] * j < n; j++) {
        if (a[i] * a[i + a[i] * j] == a[i] * j) {
          ans++;
        }
      }
      for (int j = 1; i - a[i] * j >= 0; j++) {
        if (a[i] * a[i - a[i] * j] == a[i] * j) {
          ans++;
        }
      }
    } else {
      for (int j = 1; i + a[i] * j < n && j * j < n; j++) {
        if (a[i] * a[i + a[i] * j] == a[i] * j) {
          ans++;
        }
      }
    }
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
