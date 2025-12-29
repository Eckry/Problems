#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int a, b;
  cin >> a >> b;

  int tempa = a;
  int tempb = b;
  int i = 0;
  int cnt = 0;
  int ans = 0;
  while (1) {
    if (tempa >= (1 << i)) {
      tempa -= (1 << i);
      cnt++;
    } else
      break;
    i++;
    if (tempb >= (1 << i)) {
      tempb -= (1 << i);
      cnt++;
    } else
      break;
    i++;
  }
  ans = max(ans, cnt);
  tempa = a;
  tempb = b;
  i = 0;
  cnt = 0;
  while (1) {
    if (tempb >= (1 << i)) {
      tempb -= (1 << i);
      cnt++;
    } else
      break;
    i++;
    if (tempa >= (1 << i)) {
      tempa -= (1 << i);
      cnt++;
    } else
      break;
    i++;
  }
  ans = max(ans, cnt);
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
