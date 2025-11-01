#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;

  map<int, vector<int>> opt;
  vector<pair<int, int>> a(n, pair<int, int>());
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    if (a[i].first > i + 1) {
      cout << -1 << "\n";
      return;
    }
  }
  vector<pair<int, int>> ans;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < a[i].first - 1; j++) {
      ans.push_back({a[i].second, a[j].second});
    }
  }
  cout << ans.size() << "\n";
  for (auto par : ans) {
    cout << par.first + 1 << " " << par.second + 1 << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  T = 1;
  while (T--)
    solve();
}
