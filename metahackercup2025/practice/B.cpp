#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int INF = 1e9 + 7;
void solve() {

  int r, c;
  cin >> r >> c;
  int s;
  cin >> s;

  vector<string> a(r);
  for (int i = 0; i < r; i++) {
    cin >> a[i];
  }
  vector<vector<int>> d(r, vector<int>(c, INF));
  queue<pair<int, int>> q;
  vector<vector<int>> d2(r, vector<int>(c, INF));
  vector<vector<int>> vis(r, vector<int>(c, 0));
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (a[i][j] == '#') {
        q.push({i, j});
        d2[i][j] = -1;
      }
      d[i][j] = min(d[i][j], i);
      d[i][j] = min(d[i][j], j);
      d[i][j] = min(d[i][j], r - i - 1);
      d[i][j] = min(d[i][j], c - j - 1);
    }
  }

  while (!q.empty()) {
    auto v = q.front();
    int i = v.first;
    int j = v.second;
    q.pop();
    if (vis[i][j]) {
      continue;
    }
    vis[i][j] = 1;
    if (i != 0 && !vis[i - 1][j]) {
      q.push({i - 1, j});
      d2[i - 1][j] = min(d2[i - 1][j], d2[i][j] + 1);
    }
    if (i != r - 1 && !vis[i + 1][j]) {
      q.push({i + 1, j});
      d2[i + 1][j] = min(d2[i + 1][j], d2[i][j] + 1);
    }
    if (j != 0 && !vis[i][j - 1]) {
      q.push({i, j - 1});
      d2[i][j - 1] = min(d2[i][j - 1], d2[i][j] + 1);
    }
    if (j != c - 1 && !vis[i][j + 1]) {
      q.push({i, j + 1});
      d2[i][j + 1] = min(d2[i][j + 1], d2[i][j] + 1);
    }
  }

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      d[i][j] = min(d[i][j], d2[i][j]);
    }
  }
  int ans = 0;
  vis = vector<vector<int>>(r, vector<int>(c, 0));
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (!vis[i][j] && d[i][j] >= s) {
        int cnt = 0;
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()) {
          auto par = q.front();
          int u = par.first;
          int v = par.second;
          q.pop();
          if (vis[u][v])
            continue;
          cnt++;
          vis[u][v] = 1;
          if (u != 0 && d[u - 1][v] >= s && !vis[u - 1][v]) {
            q.push({u - 1, v});
          }
          if (u != r - 1 && d[u + 1][v] >= s && !vis[u + 1][v]) {
            q.push({u + 1, v});
          }
          if (v != 0 && d[u][v - 1] >= s && !vis[u][v - 1]) {
            q.push({u, v - 1});
          }
          if (v != c - 1 && d[u][v + 1] >= s && !vis[u][v + 1]) {
            q.push({u, v + 1});
          }
        }
        ans = max(cnt, ans);
      }
    }
  }
  // cout << "\n";
  // for (int i = 0; i < r; i++) {
  //   for (int j = 0; j < c; j++) {
  //     cout << d[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  //
  // cout << "\n";
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  int i = 1;
  while (T--) {
    cout << "Case #" << i << ": ";
    i++;
    solve();
  }
}
