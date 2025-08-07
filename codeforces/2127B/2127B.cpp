#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                                                             \
  cin.tie(0);                                                                  \
  cin.sync_with_stdio(0);                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cout.tie(0);

void solve() {
  int n, x;
  cin >> n >> x;
  string s;
  cin >> s;
  x--;
  if (x == 0 || x == n - 1) {
    cout << 1 << "\n";
    return;
  }
  int blackright = 0;
  int whiteright = 0;
  int whiterightbefore = 0;
  int flg = 0;
  for (int i = x + 1; i < n; i++) {
    if (s[i] == '#') {
      blackright++;
      flg = 1;
    }
    if (s[i] == '.' && flg) {
      whiteright++;
    }
    if (s[i] == '.' && !flg) {
      whiterightbefore++;
    }
  }
  flg = 0;
  int blackleft = 0;
  int whiteleftbefore = 0;
  int whiteleft = 0;
  for (int i = x - 1; i >= 0; i--) {
    if (s[i] == '.' && flg)
      whiteleft++;
    if (s[i] == '.' && !flg)
      whiteleftbefore++;
    if (s[i] == '#') {
      flg = 1;
      blackleft++;
    }
  }
  int x1 =
      min(whiteleft + blackleft, whiterightbefore + whiteright + blackright);
  int x2 =
      min(whiteleft + blackleft + whiteleftbefore, whiteright + blackright);
  cout << max(x1, x2) + 1 << "\n";
}
int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
}
