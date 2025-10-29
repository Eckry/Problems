#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a == b && b == c && c == d) {
    cout << "YES" << "\n";
  } else
    cout << "NO" << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
