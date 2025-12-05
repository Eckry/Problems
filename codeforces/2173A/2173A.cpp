#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int cnt = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      cnt = k;
      continue;
    }
    if (cnt) {
      cnt--;
      continue;
    }
    if (!cnt)
      ans++;
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
