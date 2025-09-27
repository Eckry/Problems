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
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;
  vector<int> dp(n + 1, 0);
  vector<vector<int>> mp(n + 1, vector<int>());
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) {
      dp[i + 1] = dp[i] + 1;
      continue;
    }
    if (mp[a[i]].size()) {
      mp[a[i]].push_back(i);
      if (mp[a[i]].size() >= a[i]) {
        dp[i + 1] = max(dp[mp[a[i]][mp[a[i]].size() - a[i]]] + a[i], dp[i]);
      } else {
        dp[i + 1] = dp[i];
      }
    } else {
      mp[a[i]].push_back(i);
      dp[i + 1] = dp[i];
    }
  }
  cout << dp[n] << "\n";
}

int main() {
  optimize();
  int T;
  cin >> T;
  while (T--)
    solve();
}
