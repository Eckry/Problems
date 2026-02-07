#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  int odd = 0;
  int even = 0;
  for (int i = 0; i < n; i++) {
    if (i & 1) {
      if (a[i] == '1') {
        odd++;
      }
      if (b[i] == '1') {
        even++;
      }
    } else {
      if (a[i] == '1') {
        even++;
      }
      if (b[i] == '1') {
        odd++;
      }
    }
  }
  if (even > n / 2 || odd > (n + 1) / 2) {
    cout << "NO\n";
  } else
    cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
