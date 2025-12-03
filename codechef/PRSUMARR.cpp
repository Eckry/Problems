#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;

  if (n == 1) {
    cout << 1 << "\n";
    return;
  }
  int fact = 1;
  int i = 2;

  while (i * i <= n && n > 1) {
    while (n > 1 && n % i == 0) {
      fact++;
      n /= i;
    }
    i++;
  }
  if (n == 1)
    fact--;
  if (fact == 1) {
    cout << 1 << "\n";
    return;
  }

  if (fact == 2) {
    cout << 2 << "\n";
    return;
  } else {
    cout << 3 << "\n";
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
