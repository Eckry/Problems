#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n, s;
  cin >> n >> s;
  vector<vector<ll>> point(n, vector<ll>(4));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> point[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int dx = point[i][0];
    int dy = point[i][1];
    int x = point[i][2];
    int y = point[i][3];
    if (dx == dy) {
      if (x == y) {
        ans++;
      }
    } else {
      if (x + y == s) {
        ans++;
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
