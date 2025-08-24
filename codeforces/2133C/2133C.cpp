#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                                                             \
  cin.tie(0);                                                                  \
  cin.sync_with_stdio(0);                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cout.tie(0);

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> con(n + 1);
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    cout << "? " << i << " " << n << " ";
    for (int j = 1; j <= n; j++) {
      cout << j << " ";
    }
    cout << endl;
    int x;
    cin >> x;
    mx = max(mx, x);
    con[x].push_back(i);
  }

  int prev = con[mx][0];
  vector<int> ans;

  ans.push_back(con[mx][0]);
  while (mx > 1) {
    for (int i = 0; i < con[mx - 1].size(); i++) {
      int x = con[mx - 1][i];
      cout << "? " << prev << " " << 2 << " " << prev << " " << x << endl;
      int y;
      cin >> y;
      if (y != 1) {
        prev = x;
        mx--;
        ans.push_back(prev);
        break;
      }
    }
  }
  cout << "! " << ans.size() << " ";
  for (auto c : ans)
    cout << c << " ";
  cout << endl;
}

int main() {
  int T;
  optimize();
  cin >> T;
  while (T--)
    solve();
}
