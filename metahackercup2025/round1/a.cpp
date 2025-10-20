#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;
  int mx = 0;
  for (int i = 0; i < n - 1; i++) {
    mx = max(mx, abs(a[i + 1] - a[i]));
  }
  cout << mx << "\n";
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
