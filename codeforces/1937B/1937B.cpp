#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<string> a(2);
  cin >> a[0];
  cin >> a[1];

  int ans = 1;
  int best = 1;
  string p = "";
  int j = n - 1;
  for (int i = n - 1; i > 0; i--) {
    if (a[1][i - 1] > a[0][i]) {
      best = -10000000;
    }
    if (a[1][i - 1] < a[0][i]) {
      // cout << i << "i\n";
      j = i - 1;
      best = 1;
      ans = 1;
    }
    if (a[1][i - 1] == a[0][i]) {
      best++;
    }
    ans = max(ans, best);
  }
  for (int i = 0; i <= j; i++) {
    p += a[0][i];
  }
  for (int i = j; i < n; i++) {
    p += a[1][i];
  }
  cout << p << "\n";
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
