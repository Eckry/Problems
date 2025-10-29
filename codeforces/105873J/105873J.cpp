#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int pref = 0;
  int ans = 0;
  vector<int> mp((1 << 26), -1);
  for (int i = 0; i < n; i++) {
    pref ^= 1 << (s[i] - 'a');
    for (int j = 0; j < 26; j++) {
      int lol = pref ^ (1 << j);
      if (mp[lol] != -1) {
        ans = max(ans, i - mp[lol]);
      }
    }
    if (mp[pref] == -1) {
      mp[pref] = i;
    } else {
      ans = max(ans, i - mp[pref]);
    }
    if (pref == 0 || __builtin_popcount(pref) == 1) {
      ans = max(ans, i + 1);
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  T = 1;
  while (T--)
    solve();
}
