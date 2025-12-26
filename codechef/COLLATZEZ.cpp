#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n;
  cin >> n;

  if (n == 3 || n == 1 || n == 2) {
    cout << "YES\n";
    return;
  }
  if (!(1 & n) && !(2 & n)) {
    cout << "YES\n";
    return;
  }
  while (n % 2 == 0) {
    n >>= 1;
  }
  if (n == 3 || n == 1 || n == 2) {
    cout << "YES\n";
    return;
  }
  if (!(1 & n) && !(2 & n)) {
    cout << "YES\n";
    return;
  }
  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
