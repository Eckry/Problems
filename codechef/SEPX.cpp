#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;

  int mn = INT_MAX;
  int mx = 0;
  int ok = 0;

  for (int i = 0; i < n; i++) {
    mn = min(mn, a[i]);
    mx = max(mx, a[i]);
    if (a[i] == x)
      ok = 1;
  }
  if (ok || x < mn || x > mx) {
    cout << "Yes" << "\n";
  } else
    cout << "No" << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
