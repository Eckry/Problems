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
  string s;
  cin >> s;
  vector<int> bits(n, 0);
  bits[0] = 1 << (s[0] - 'a');
  unordered_map<int, int> mp;
  mp[bits[0]] = 1;
  mp[0] = 0;
  int ans = 0;
  for (int i = 1; i < n; i++) {
    bits[i] = (bits[i - 1] ^ (1 << (s[i] - 'a')));
    if (mp.count(bits[i])) {
      ans = max(i - mp[bits[i]] + 1, ans);
    } else {
      mp[bits[i]] = i + 1;
    }
    for (int j = 0; j < 26; j++) {
      int x = (1 << j);
      if (mp.count(bits[i] ^ x)) {
        ans = max(ans, i + 1 - mp[bits[i] ^ x]);
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  optimize();
  int T;
  T = 1;
  while (T--)
    solve();
}
