#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n, x, y;
  cin >> n >> x >> y;
  string s;
  cin >> s;

  if (x < 0)
    x = -x;
  if (y < 0)
    y = -y;

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '4') {
    } else {
      cnt++;
    }
  }

  int sx = cnt;
  int sy = n;
  while (sy >= cnt) {
    if (x <= sx && y <= sy) {
      cout << "YES\n";
      return;
    }
    sx++;
    sy--;
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
