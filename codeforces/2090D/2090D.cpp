#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (auto &g : a)
    cin >> g;

  vector<vector<int>> g(n, vector<int>(m, 2));
  for (int i = 0; i < n; i++) {
    int flg = 0;
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '1' && !flg) {
        g[i][j] = 1;
      }
      if (a[i][j] == '0') {
        flg = 1;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    int flg = 0;
    for (int j = 0; j < n; j++) {
      if (a[j][i] == '1' && !flg) {
        g[j][i] = 1;
      }
      if (a[j][i] == '0') {
        flg = 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '1' && g[i][j] == 2) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
