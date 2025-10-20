#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  for (int i = 0; i < n; i++) {
    cout << 1 << " ";
  }
  for (int i = 0; i < n - 1; i++) {
    cout << 1 << " ";
  }
  cout << b << "\n";
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
