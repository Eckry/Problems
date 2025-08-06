#include <bits/stdc++.h>

#define ll long long
using namespace std;

void solve() {
  ll n;
  cin >> n;
  vector<ll> b(n * 2);
  for (auto &c : b)
    cin >> c;
  sort(b.begin(), b.end());
  vector<ll> ans(2 * n);
  int idx = 0;
  for (int i = 1; i < 2 * n; i += 2) {
    ans[i] = b[idx];
    idx++;
  }
  for (int i = 0; i < 2 * n; i += 2) {
    ans[i] = b[idx];
    idx++;
  }
  ll sm = ans[0] + ans[2 * n - 1];

  for (int i = 1; i < 2 * n - 1; i += 2) {
    sm -= ans[i];
  }
  for (int i = 2; i < 2 * n - 1; i += 2) {
    sm += ans[i];
  }
  for (int i = 0; i < 2 * n - 1; i++) {
    cout << ans[i] << " ";
  }
  cout << sm << " " << ans[2 * n - 1] << "\n";
}

int main() {
  int t;
  cin >> t;

  while (t--)
    solve();
  return 0;
}
