#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  while (n >= a) {
    n -= (a - b);
  }
  cout << n << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
