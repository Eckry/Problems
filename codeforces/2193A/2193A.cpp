#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n, s, x;
  cin >> n >> s >> x;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;
  ll sm = 0;
  for (int i = 0; i < n; i++) {
    sm += a[i];
  }
  if (sm > s) {
    cout << "NO" << "\n";
  } else if ((s - sm) % x == 0) {
    cout << "YES\n";
  } else {

    cout << "NO" << "\n";
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
