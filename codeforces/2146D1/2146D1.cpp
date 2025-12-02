#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int l, r;
  cin >> l >> r;
  vector<int> a(r + 1, -1);
  vector<int> b(r + 1);

  iota(b.begin(), b.end(), 0);
  if (r == 0) {
    cout << 0 << "\n0\n";
    return;
  }

  for (int i = r; i > 0; i--) {
    int bits = 31 - __builtin_clz(i);
    int x = i;
    for (int j = bits; j >= 0; j--) {
      x = (x ^ (1 << j));
    }
    if (a[x] != -1 || a[i] != -1)
      continue;
    a[x] = i;
    a[i] = x;
  }
  ll ans = 0;
  if (a[0] == -1)
    a[0] = 0;
  for (int i = 0; i < r + 1; i++) {
    ans += a[i] | b[i];
  }
  cout << ans << "\n";
  for (auto c : a) {
    cout << c << " ";
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
