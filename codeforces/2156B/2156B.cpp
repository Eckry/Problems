#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  int B = 0;
  for (int i = 0; i < n; i++)
    if (s[i] == 'B')
      B++;
  while (q--) {
    int x;
    cin >> x;
    if (B) {
      int ans = 0;
      while (x) {
        for (int i = 0; i < n; i++) {
          if (s[i] == 'A') {
            x--;
          } else {
            x /= 2;
          }
          ans++;
          if (!x)
            break;
        }
      }
      cout << ans << "\n";
    } else {
      cout << x << "\n";
    }
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
