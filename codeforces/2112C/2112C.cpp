
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;
  long long ans = 0;
  for (int i = 0; i < n - 2; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      int idx =
          upper_bound(a.begin() + j + 1, a.end(), a[n - 1] - a[i] - a[j]) -
          a.begin();
      int idx2 =
          lower_bound(a.begin() + j + 1, a.end(), a[i] + a[j]) - a.begin();
      if (idx < idx2)
        ans += idx2 - idx;
    }
  }
  cout << ans << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}
