#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;

  if (a[0] >= a[1]) {
    cout << a[0] + a[1] << "\n";
    return;
  }

  if (n == 2) {
    cout << min(a[0] * 2, a[0] + a[1]) << "\n";
    return;
  }

  if (a[0] + a[1] <= a[0] * 2) {
    cout << a[0] + a[1] << "\n";
    return;
  }
  cout << a[0] * 2 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
