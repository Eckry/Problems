#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;

  if (a[0] == -1 && a[n - 1] == -1) {
    a[0] = 0;
    a[n - 1] = 0;
  }
  if (a[0] == -1) {
    a[0] = a[n - 1];
  }
  if (a[n - 1] == -1) {
    a[n - 1] = a[0];
  }
  ll ans = 0;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] == -1)
      a[i] = 0;
  }
  for (int i = 0; i < n - 1; i++) {
    ans += a[i + 1] - a[i];
  }
  cout << abs(ans) << "\n";
  for (auto c : a)
    cout << c << " ";
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
