#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n, m;
  cin >> n >> m;
  // vector<vector<int>> c(n, vector<int>(m, 0));
  // for (int i = 0; i < m; i++) {
  //   c[0][i] = i;
  // }
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < m; j++) {
  //     c[i][j] = max(i, j);
  //   }
  // }
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < m; j++) {
  //     cout << c[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  int i = 0;
  int j = 0;
  cout << "? " << i + 1 << " " << j + 1 << endl;
  int x;
  cin >> x;
  if (x >= min(n, m)) {
    if (n < m) {
      j += x;
      cout << "? " << i + 1 << " " << j + 1 << endl;
      cin >> x;
      i += x;
      cout << "! " << i + 1 << " " << j + 1 << endl;
    } else {
      i += x;
      cout << "? " << i + 1 << " " << j + 1 << endl;
      cin >> x;
      j += x;
      cout << "! " << i + 1 << " " << j + 1 << endl;
    }
  } else {
    j += x;
    i += x;
    cout << "? " << i + 1 << " " << j + 1 << endl;
    cin >> x;
    i -= x;
    cout << "? " << i + 1 << " " << j + 1 << endl;
    cin >> x;
    if (x == 0) {
      cout << "! " << i + 1 << " " << j + 1 << endl;
    } else {
      cout << "! " << j + 1 << " " << i + 1 << endl;
    }
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
