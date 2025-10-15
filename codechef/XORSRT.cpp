#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n, k;
  cin >> n >> k;
  if (k == 0) {
    for (int i = 1; i <= n; i++) {
      cout << i << " ";
    }
    cout << "\n";
    return;
  }
  int y = -1;
  int x = -1;
  for (int i = 1; i <= n; i++) {
    if ((i ^ k) <= n && (i ^ k) >= 1) {
      y = (i ^ k);
      x = i;
      break;
    }
  }
  if (y == -1) {
    cout << -1 << "\n";
    return;
  }
  int num = (1 << (31 - __builtin_clz(y)));
  cout << num << "\n";
  cout << x << " " << y << "\n";
  for (int i = 1 + (x == 1); i < num; i++) {
    if (i == x)
      continue;
    cout << i << " ";
  }
  cout << y << " ";
  cout << x << " ";
  for (int i = num + (x == num); i < y; i++) {
    if (i == y)
      continue;
    cout << i << " ";
  }
  for (int i = y + 1; i <= n; i++) {
    cout << i << " ";
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
