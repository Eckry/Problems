#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n, 0));
  if (n == 2) {
    cout << -1 << "\n";
    return;
  } else if (n == 3) {
    cout << "1 1 1\n0 1 1\n0 1 1\n";
    return;
  }
  for (int i = 0; i < n; i++) {
    a[0][i] = 1;
    a[i][0] = 1;
    a[n - 1][i] = 1;
    a[i][n - 1] = 1;
  }
  a[1][n - 2] = 1;

  for (auto vec : a) {
    for (auto c : vec) {
      cout << c << " ";
    }
    cout << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
