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
  if (3 - n % 3 == 3) {
    cout << 0 << "\n";
  } else
    cout << 3 - n % 3 << "\n";
}

int main() {
  optimize() int T;
  cin >> T;
  while (T--)
    solve();
}
