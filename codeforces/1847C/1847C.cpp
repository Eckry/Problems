#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;
  vector<int> vis(n, 0);
  map<int, int> mp;
  int acc = 0;
  for (int i = (1 << 8) - 1; i >= 0; i--) {
    acc = 0;
    for (int j = 0; j < n; j++) {
      acc ^= a[j];
      int seek = i ^ acc;
      if (acc == i || mp.find(seek) != mp.end()) {
        cout << i << "\n";
        return;
      } else {
        mp[acc] = 1;
      }
    }
    mp.clear();
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
