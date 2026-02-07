#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  string s, t;
  cin >> s >> t;

  vector<int> cnt(26, 0);
  for (auto c : t) {
    cnt[c - 'a']++;
  }
  for (auto c : s) {
    cnt[c - 'a']--;
  }
  for (int i = 0; i < 26; i++) {
    if (cnt[i] < 0) {
      cout << "Impossible\n";
      return;
    }
  }
  sort(t.begin(), t.end());
  string ans = "";
  int n = s.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 26; j++) {
      while (cnt[j] && s[i] - 'a' > j) {
        ans += char(97 + j);
        cnt[j]--;
      }
    }
    ans += s[i];
  }
  for (int i = 0; i < 26; i++) {
    while (cnt[i]) {
      ans += char(97 + i);
      cnt[i]--;
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
