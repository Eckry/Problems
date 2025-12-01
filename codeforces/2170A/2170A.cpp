#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;

  vector<vector<int>> grid(n, vector<int>(n));
  int cnt = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      grid[i][j] = cnt;
      cnt++;
    }
  }

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ll sm = grid[i][j];
      if (i)
        sm += grid[i - 1][j];
      if (i != n - 1)
        sm += grid[i + 1][j];
      if (j)
        sm += grid[i][j - 1];
      if (j != n - 1)
        sm += grid[i][j + 1];
      ans = max(ans, sm);
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
