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
  for (int i = 0; i < n; i++) {
    mp[a[i]]++;
  }
  int ans = 0;
  for (auto [key, val] : mp) {
    if (val < key) {
      ans += val;
    } else {
      ans += val - key;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
