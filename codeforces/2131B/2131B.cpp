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

  if (n == 2) {
    cout << -1 << " " << 2 << "\n";
    return;
  }
  for (int i = 0; i < n - 1; i++) {
    if (i & 1)
      cout << 3 << " ";
    else
      cout << -1 << " ";
  }
  if (n & 1) {
    cout << -1 << " ";
  } else {
    cout << 2 << " ";
  }
  cout << "\n";
}

int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
}
