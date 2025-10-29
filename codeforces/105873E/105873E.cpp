#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;
  for (int i = 0; i < n; i++) {
    if (m <= a[i]) {
      cout << i + 1 << "\n";
      return;
    }
  }
  cout << -1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  T = 1;
  while (T--)
    solve();
}
