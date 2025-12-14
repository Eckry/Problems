#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int ans = 0;
  int cnt = 0;
  int flg = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      cnt = 0;
    }
    if (s[i] == '0') {
      flg = 1;
      cnt++;
      ans = max(cnt, ans);
    }
  }
  if (!flg) {
    cout << ans << "\n";
    return;
  }
  int end = n - 1;
  int start = 0;
  while (end >= 0 && s[end] == '0')
    end--;
  while (start < n && s[start] == '0')
    start++;
  ans = max(ans, n - 1 - end + start);
  // cout << start << " " << end << "\n";
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
