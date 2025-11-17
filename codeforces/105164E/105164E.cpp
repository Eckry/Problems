#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int a, b, k;
  cin >> a >> b >> k;
  for (int i = 1; i <= k; i++) {
    cout << a * i + b << " ";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  T = 1;
  while (T--)
    solve();
}
