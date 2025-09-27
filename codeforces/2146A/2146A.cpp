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
  vector<int> mp(n + 1, 0);
  for (auto c : a) {
    mp[c]++;
  }

  int target = 100;
  int ans = 0;
  int cnt = 0;
  while (target >= 1) {
    cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (mp[i] >= target) {
        cnt += target;
      }
    }
    // cout << target << " " << cnt << "\n";
    target--;
    ans = max(cnt, ans);
  }
  cout << ans << "\n";
}

int main() {
  optimize();
  int T;
  cin >> T;
  while (T--)
    solve();
}
