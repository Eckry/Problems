#include <bits/stdc++.h>

using namespace std;

void solve() {

  long long n, k;
  cin >> n >> k;

  if (k & 1) {
    for (int i = 0; i < n - 1; i++) {
      cout << n << " ";
    }
    cout << n - 1 << "\n";
  } else {
    for (int i = 0; i < n - 2; i++) {
      cout << n - 1 << " ";
    }
    cout << n << " ";
    cout << n - 1 << "\n";
  }
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}
