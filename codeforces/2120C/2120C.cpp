#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n, m;
  cin >> n >> m;

  if (n * (n + 1) / 2 < m || m < n) {
    cout << -1 << "\n";
    return;
  }
  ll sm = n;
  ll v = 1;
  int i = 1;
  while (sm + n - i < m) {
    sm += n - i;
    i++;
    v++;
  }

  ll diff = m - sm;
  if (diff == 0) {
    cout << v << "\n";
    for (int i = 1; i <= n; i++) {
      if (i != v) {
        cout << v << " " << i << "\n";
      }
    }
    return;
  }

  v++;
  int limit = v + diff - 1;
  cout << v << "\n";

  for (int i = 1; i < v; i++) {
    cout << v << " " << i << "\n";
  }
  for (int i = v + 1; i <= limit; i++) {
    cout << v << " " << i << "\n";
  }
  for (int i = limit + 1; i <= n; i++) {
    cout << v - 1 << " " << i << "\n";
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
