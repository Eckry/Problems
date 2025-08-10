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
  vector<int> initial = a;
  if (a[n - 1] != b[n - 1]) {
    cout << "NO" << "\n";
    return;
  }
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] == b[i]) {
      continue;
    }
    if (b[i] == 0 && a[i + 1] == a[i]) {
      a[i] = 0;
      continue;
    }
    if (b[i] == 0 && initial[i + 1] == initial[i]) {
      a[i] = 0;
      continue;
    }
    if (b[i] == (a[i] ^ a[i + 1])) {
      a[i] = (a[i] ^ a[i + 1]);
      continue;
    }
    if (b[i] == (initial[i] ^ initial[i + 1])) {
      a[i] = (initial[i] ^ initial[i + 1]);
      continue;
    }
    cout << "NO" << "\n";
    return;
  }
  cout << "YES" << "\n";
}

int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
}
