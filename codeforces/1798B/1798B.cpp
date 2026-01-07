#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int m;
  cin >> m;
  vector<vector<int>> a(m, vector<int>());
  set<int> st;
  for (int i = 0; i < m; i++) {
    int n;
    cin >> n;
    a[i] = vector<int>(n);
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      st.insert(a[i][j]);
    }
  }
  vector<int> ans(m, -1);
  for (int i = m - 1; i >= 0; i--) {
    for (int j = 0; j < a[i].size(); j++) {
      if (ans[i] == -1 && st.find(a[i][j]) != st.end()) {
        ans[i] = a[i][j];
      }
      st.erase(a[i][j]);
    }
    if (ans[i] == -1) {
      cout << -1 << "\n";
      return;
    }
  }
  for (auto c : ans) {
    cout << c << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
