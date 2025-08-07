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
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;
  int flg = 1;
  int obj = -1;
  for (int i = 0; i < n; i++) {
    if (a[i] != -1) {
      flg = 0;
      if (a[i] != 0)
        obj = a[i];
    }
  }
  if (flg) {
    cout << "YES" << "\n";
    return;
  }
  if (obj == -1) {
    cout << "NO" << "\n";
    return;
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == -1) {
      a[i] = obj;
    }
  }
  for (int i = 0; i < n - 1; i++) {
    if (a[i] != a[i + 1]) {
      cout << "NO" << "\n";
      return;
    }
  }

  cout << "YES" << "\n";
}

int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
}
