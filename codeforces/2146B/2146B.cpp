#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                                                             \
  cin.tie(0);                                                                  \
  cin.sync_with_stdio(0);                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cout.tie(0);

void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> cnt(m + 1, {0, -1});
  for (int i = 0; i < n; i++) {
    int l;
    cin >> l;
    for (int j = 0; j < l; j++) {
      int x;
      cin >> x;
      cnt[x].first++;
      cnt[x].second = i;
    }
  }
  set<int> st;
  for (int i = 1; i <= m; i++) {
    if (cnt[i].first == 0) {
      cout << "NO" << "\n";
      return;
    }
    if (cnt[i].first == 1) {
      // cout << i << "\n";
      st.insert(cnt[i].second);
    }
  }
  if(st.size() + 2 <= n) {
    cout << "YES" << "\n";
  } else {
    cout << "NO" << "\n";
  }

}

int main() {
  optimize();
  int T;
  cin >> T;
  while (T--)
    solve();
}
