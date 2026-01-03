#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n, x;
  cin >> n >> x;
  int bit = 31;
  for (int i = 0; i <= 31; i++) {
    if (!(x & (1 << i))) {
      bit = i;
      break;
    }
  }
  int y = (1 << bit);
  vector<int> ans;
  int cnt = 0;
  while (cnt < y && ans.size() < n) {
    ans.push_back(cnt);
    cnt++;
  }
  while (ans.size() < n) {
    ans.push_back(x);
  }
  int ors = 0;
  for (int i = 0; i < n; i++) {
    ors |= ans[i];
  }
  if (ors != x) {
    ans[n - 1] = x;
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
