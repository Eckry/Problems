#include <bits/stdc++.h>

using namespace std;

void solve() {
  vector<int> a(4);
  cin >> a[0];
  cin >> a[1];
  cin >> a[2];
  cin >> a[3];
  sort(a.begin(), a.end());
  int ans = 1;
  for (int i = 0; i < 4; i++) {
    if (ans == a[i])
      ans++;
  }
  cout << ans << "\n";
}

int main() {
  int t;
  t = 1;
  while (t--)
    solve();
}
