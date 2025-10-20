#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int ans = 1;
  int start = 0;
  int cnt = 0;
  while (start < n && s[start] == '0')
    start++;
  if (start == n) {
    cout << 0 << "\n";
    return;
  }
  for (int i = start; i < n; i++) {
    if (s[i] == '0') {
      cnt++;
    }
    if (s[i] == '1') {
      if (cnt >= k - 1) {
        ans++;
      }
      cnt = 0;
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
