#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> ans(n);
  int cnt = 2;
  ans[0] = 1;
  vector<int> used(n + 1, 0);
  int start = 0;
  used[1] = 1;
  for (int i = 1; i < n - 1; i += 3) {
    ans[i] = cnt;
    used[cnt] = 1;
    start = i;
    if (cnt + 2 > n)
      break;
    ans[i + 1] = cnt + 2;
    used[cnt + 2] = 1;
    cnt += 4;
    if (cnt > n)
      break;
  }
  cnt = 3;
  int mul = 1;
  for (int i = start + 3; i < n - 1; i += 3) {
    ans[i] = cnt * mul;
    used[cnt * mul] = 1;
    if (cnt * (mul + 2) > n)
      break;
    ans[i + 1] = cnt * (mul + 2);
    used[cnt * (mul + 2)] = 1;
    mul += 4;
    if (cnt * mul > n)
      break;
  }
  cnt = 1;
  for (int i = 0; i < n; i++) {
    if (ans[i] == 0) {
      while (used[cnt])
        cnt++;
      ans[i] = cnt;
      used[cnt] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
