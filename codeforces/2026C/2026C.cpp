#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string res(n, 'x');
  int one = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '0') {
      one = max(0, one - 1);
      res[i] = 'y';
    } else {
      one++;
    }
  }
  int need = (one + 1) / 2;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      res[i] = 'y';
      cnt++;
    }
    if (cnt == need)
      break;
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (res[i] == 'y')
      ans += i + 1;
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
