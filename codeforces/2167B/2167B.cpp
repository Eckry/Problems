#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string t;
  cin >> t;
  vector<int> cnt(26, 0);
  vector<int> cnt2(26, 0);
  for (int i = 0; i < n; i++) {
    cnt[s[i] - 'a']++;
  }
  for (int i = 0; i < n; i++) {
    cnt2[t[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    if (cnt[i] != cnt2[i]) {
      cout << "NO" << "\n";
      return;
    }
  }
  cout << "YES" << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
