#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;

  int mn = INT_MAX;
  int mx = 0;
  for (auto c : a) {
    mn = min(mn, c);
    mx = max(mx, c);
  }
  if (mx > mn + 1 || mx == mn) {
    cout << mx - 1 << "\n";
    return;
  }
  cout << mn - 1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
