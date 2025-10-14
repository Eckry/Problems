#include <bits/stdc++.h>
#include <memory>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (auto &c : a)
    cin >> c;
  for (auto &c : b)
    cin >> c;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    mp[a[i]] = i;
  }
  vector<pair<int, int>> ans;
  vector<int> indices(n);
  iota(indices.begin(), indices.end(), 0);
  sort(indices.begin(), indices.end(),
       [&](int x, int y) { return a[x] < a[y]; });
  for (int i = 0; i < n; i++) {
    int idx = indices[i];
    // cout << idx << "\n";
    if (a[idx] == b[idx])
      continue;
    if (a[idx] > b[idx]) {
      cout << -1 << "\n";
      return;
    }
    if (mp.count(b[idx])) {
      int j = mp[b[idx]];
      ans.push_back({idx, j});
    } else {
      cout << -1 << "\n";
      return;
    }
  }
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) {
    auto c = ans[i];
    cout << c.first + 1 << " " << c.second + 1 << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  int i = 0;
  while (T--) {
    cout << "Case " << "#" << i + 1 << ": ";
    i++;
    solve();
  }
}
