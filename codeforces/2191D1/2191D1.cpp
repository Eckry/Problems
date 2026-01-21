#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<int> suf(n, -1);
  for (int i = n - 2; i >= 0; i--) {
    suf[i] = suf[i + 1];
    if (s[i] == '(') {
      suf[i] = i;
    }
  }
  vector<int> cnt(n, 0);
  for (int i = n - 2; i >= 0; i--) {
    cnt[i] = cnt[i + 1] + (s[i] == ')');
  }
  int ans = -1;
  int b = 0;
  int len = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      b++;
      len++;
    } else {
      if (suf[i] == -1)
        break;
      int idx = suf[i];
      if (cnt[i] >= b + 1) {
        ans = max(ans, len + n - idx - 1);
      }
      len++;
      b--;
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
