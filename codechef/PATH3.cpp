#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;

  ll mn = a[0];
  ll mx = a[n - 1];
  for (int i = 1; i < n; i++) {
    mn += 2 * a[i];
  }
  for (int i = n - 2; i >= 0; i--) {
    mx = 2 * mx + a[i];
  }
  cout << mn << " " << mx << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
