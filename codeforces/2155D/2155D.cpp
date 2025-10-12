#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                                                             \
  cin.tie(0);                                                                  \
  cin.sync_with_stdio(0);                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cout.tie(0);

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    for (int j = 1; j + i <= n; j++) {
      cout << j << " " << j + i << endl;
      int x;
      cin >> x;
      if (x)
        return;
    }
  }
}
// 1 2 3
// 0 x x

int main() {
  optimize() int T;
  cin >> T;
  while (T--)
    solve();
}
