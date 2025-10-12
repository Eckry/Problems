#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                                                             \
  cin.tie(0);                                                                  \
  cin.sync_with_stdio(0);                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cout.tie(0);


void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  for (auto &c : a)
    cin >> c;

  for (int i = 1; i < m; i++) {
    if (a[i - 1] >= a[i]) {
      cout << 1 << "\n";
      return;
    }
  }
  cout << n - a[m - 1] + 1 << "\n";
}


int main() {
  optimize() int T;
  cin >> T;
  while (T--)
    solve();
}
