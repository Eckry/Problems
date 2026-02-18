#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;

  int ans = 0;
  vector<int> cnt(101, 0);
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) {
      ans++;
      cnt[a[i]]++;
    } else if (cnt[a[i] - 1]) {
      ans++;
      cnt[a[i]]++;
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
