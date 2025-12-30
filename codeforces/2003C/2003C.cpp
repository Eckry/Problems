#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> cnt(26, 0);
  for (auto c : s) {
    cnt[c - 'a']++;
  }

  string ans = "";
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < 26; i++) {
      if (cnt[i]) {
        cnt[i]--;
        ans += char(i + 97);
      }
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
