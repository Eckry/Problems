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
  vector<int> b(n);
  for (auto &c : a)
    cin >> c;
  for (auto &c : b)
    cin >> c;

  int cnta = 0;
  int cntb = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > b[i]) {
      cnta += a[i] - b[i];
    }
    if (b[i] > a[i])
      cntb += b[i] - a[i];
  }

  cout << cnta + 1 << "\n";
}

int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
}
