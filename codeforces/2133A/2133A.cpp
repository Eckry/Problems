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
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j == i)
        continue;
      if (a[i] == a[j]) {
        cout << "YES" << "\n";
        return;
      }
    }
  }

  cout << "NO" << "\n";
}

int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
}
