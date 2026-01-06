#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;
  map<int, int> mp;
  for (auto c : a) {
    mp[c]++;
  }
  int cnt = 0;
  vector<int> op;
  for (auto [k, v] : mp) {
    if (v >= 2) {
      cnt += (v >> 1);
      while (v > 1) {
        v -= 2;
        op.push_back(k);
      }
    }
  }
  if (cnt < 4) {
    cout << "NO\n";
    return;
  }
  int m = op.size();
  cout << "YES\n";
  int x1 = op[1];
  int x2 = op[1];
  int x3 = op[m - 1];
  int x4 = op[m - 1];
  int y1 = op[0];
  int y2 = op[m - 2];
  int y3 = op[0];
  int y4 = op[m - 2];
  cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3
       << " " << x4 << " " << y4 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
