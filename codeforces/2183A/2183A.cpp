#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;

  int ok = 0;
  int ones = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0)
      ok = 1;
    else
      ones = 1;
  }
  if (!ok) {
    cout << "Alice\n";
    return;
  }
  if (!ones) {
    cout << "Bob\n";
    return;
  }
  if (a[n - 1] == 1 || a[0] == 1) {
    cout << "Alice\n";
  } else {
    cout << "Bob\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
