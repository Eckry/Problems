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
  for (int i = 0; i < 26; i++) {
    if (cnt[i] >= 3) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
