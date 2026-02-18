#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<int> cnt(26, 0);
  for (int i = 0; i < n; i++) {
    s[i] = tolower(s[i]);
    cnt[s[i] - 'a']++;
  }
  sort(cnt.begin(), cnt.end());
  cout << cnt[25] + cnt[24] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
