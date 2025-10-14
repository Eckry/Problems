#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll INF = LONG_LONG_MAX;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll x, y;
  cin >> x >> y;
  ll obx, oby;
  cin >> obx >> oby;
  ll k;
  cin >> k;
  vector<string> orders(k);
  for (int i = 0; i < k; i++) {
    cin >> orders[i];
  }

  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                 greater<pair<int, pair<int, int>>>>
      q;

  q.push({0, {x, y}});
  vector<vector<ll>> d(n, vector<ll>(m, INF));
  d[x][y] = 0;
  // int cnt = 0;
  while (!q.empty()) {
    // if (cnt == 100) {
    //   cout << "LOL";
    //   break;
    // }
    auto v = q.top().second;
    int len = q.top().first;
    // cnt++;
    q.pop();

    if (d[v.first][v.second] != len) {
      continue;
    }
    // cout << v.first << " " << v.second << "\n";
    if (v.first == obx && v.second == oby) {
      break;
    }
    for (auto order : orders) {
      int i = v.first;
      int j = v.second;
      int succ = 0;
      for (auto let : order) {
        if (let == 'U') {
          if (i == 0 || a[i - 1][j] == '1')
            continue;
          succ++;
          i--;
        }
        if (let == 'D') {
          if (i == n - 1 || a[i + 1][j] == '1')
            continue;
          succ++;
          i++;
        }
        if (let == 'L') {
          if (j == 0 || a[i][j - 1] == '1')
            continue;
          succ++;
          j--;
        }
        if (let == 'R') {
          if (j == m - 1 || a[i][j + 1] == '1')
            continue;
          succ++;
          j++;
        }
      }
      // cout << len << " " << succ << " succ\n";
      if (v.first == i && v.second == j) {
        continue;
      }
      if (len + succ < d[i][j]) {
        d[i][j] = len + succ;
        q.push({len + succ, {i, j}});
      }
    }
  }
  if (d[obx][oby] == INF) {
    cout << -1 << "\n";
  } else
    cout << d[obx][oby] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  T = 1;
  while (T--)
    solve();
}
