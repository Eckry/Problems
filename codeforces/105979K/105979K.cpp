#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> right(n);
  vector<int> left(n);
  for (auto &c : right)
    cin >> c;
  for (auto &c : left)
    cin >> c;
  sort(right.begin(), right.end());
  sort(left.begin(), left.end());

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (right[i] + left[i] <= k) {
      ans++;
      k -= (right[i] + left[i]);
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  T = 1;
  while (T--)
    solve();
}
