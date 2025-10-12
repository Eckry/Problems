#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                                                             \
  cin.tie(0);                                                                  \
  cin.sync_with_stdio(0);                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cout.tie(0);

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int l = 0;
  int r = n - 1;
  int cnt = 0;
  for (int i = 0; i < k; i++) {
    if (s[i] == '0') {
      l++;
    }
    if (s[i] == '1') {
      r--;
    }
    if (s[i] == '2') {
      cnt++;
    }
    if (l > r)
      break;
  }
  // cout << cnt << " " << l << " " << r << "\n";
  if (r - l + 1 <= cnt || l > r) {
    for (int i = 0; i < n; i++) {
      cout << '-' << "";
    }
    cout << "\n";
    return;
  }
  if ((r - l + 1) / 2 < cnt) {
    for (int i = 0; i < l; i++)
      cout << "-";
    for (int i = 0; i < r- l +1; i++)
      cout << "?";
    for (int i = 0; i < n - r - 1; i++)
      cout << "-";
    cout << "\n";
  } else {
    for (int i = 0; i < l; i++)
      cout << "-";
    for (int i = 0; i < cnt; i++)
      cout << "?";
    for (int i = 0; i <= r - cnt - (l + cnt); i++)
      cout << "+";
    for (int i = 0; i < cnt; i++)
      cout << "?";
    for (int i = 0; i < n - r - 1; i++)
      cout << "-";
    cout << "\n";
  }
}

int main() {
  optimize() int T;
  cin >> T;
  while (T--)
    solve();
}
