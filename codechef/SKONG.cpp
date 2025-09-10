#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                                                             \
  cin.tie(0);                                                                  \
  cin.sync_with_stdio(0);                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cout.tie(0);

void solve() {
  int x, h;
  cin >> x >> h;
  cout << (x - 4) * 24 + h << "\n";
}

int main() {
  optimize() int T;
  T = 1;
  while (T--)
    solve();
}
