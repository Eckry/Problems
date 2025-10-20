#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;

  vector<int> ans(n);
  ans[0] = a[0];
  for (int i = 1; i < n; i++) {
    ans[i] = max(ans[i - 1], abs(a[i - 1] - a[i]));
    ans[i] = min(ans[i], a[i]);
  }
  vector<int> ans2(n);
  ans2[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    ans2[i] = max(ans2[i + 1], abs(a[i + 1] - a[i]));
    ans2[i] = min(ans2[i], a[i]);
  }
  for (int i = 0; i < n; i++) {
    ans[i] = min(ans[i], ans2[i]);
  }
  int res = 0;
  for (auto c : ans)
    res = max(res, c);
  cout << res << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  int i = 1;
  while (T--) {
    cout << "Case #" << i << ": ";
    i++;
    solve();
  }
}
