#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;
  int sm = 0;
  for (int i = 0; i < n - 1; i++) {
    sm += abs(a[i] - a[i + 1]);
  }
  int ans = 100000000;
  for (int i = 1; i < n - 1; i++) {
    int temp = sm;
    temp = min(temp, temp + abs(a[i - 1] - a[i + 1]) - abs(a[i] - a[i + 1]) -
                         abs(a[i - 1] - a[i]));
    ans = min(temp, ans);
  }
  ans = min(ans, sm - abs(a[0] - a[1]));
  ans = min(ans, sm - abs(a[n - 1] - a[n - 2]));
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
