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
  map<int, vector<int>> x;
  vector<int> cnt(2, 0);
  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    x[u].push_back(v);
    cnt[v]++;
  }

  ll ans = 0;
  for (auto c : x) {
    if (c.second.size() == 2)
      ans += cnt[0] + cnt[1] - 2;
  }

  for (auto c : x) {
    if (c.second.size() == 2) {
      if (x.count(c.first - 1) && x.count(c.first + 1)) {
        if (x[c.first - 1].size() == 2 && x[c.first + 1].size() == 2)
          ans += 2;
        else if (x[c.first - 1].size() == 2 || x[c.first + 1].size() == 2)
          ans++;
        else if (x[c.first - 1][0] == x[c.first + 1][0])
          ans++;
      }
    } else {
      if (x.count(c.first - 1) && x.count(c.first + 1)) {
        if (x[c.first - 1].size() == 2 && x[c.first + 1].size() == 2)
          ans++;
        else if (x[c.first - 1].size() == 2) {
          if (x[c.first + 1][0] != c.second[0])
            ans++;
        } else if (x[c.first + 1].size() == 2) {
          if (x[c.first - 1][0] != c.second[0])
            ans++;
        } else {
          if (x[c.first - 1][0] != c.second[0] &&
              x[c.first + 1][0] != c.second[0])
            ans++;
        }
      }
    }
  }
  cout << ans << "\n";
}

int main(void) {
  optimize();
  int T;
  cin >> T;
  // T = 1;
  while (T--)
    solve();
}
