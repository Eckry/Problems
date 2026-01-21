#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll b, c, d;
  cin >> b >> c >> d;

  ll a = 0;
  // cout << start << "\n";
  for (int i = 63; i >= 0; i--) {
    if (d & (1LL << i)) {
      if (c & (1LL << i)) {
        if (b & (1LL << i)) {
          // No
        }
      } else {
        if (b & (1LL << i)) {
          // No
        } else {
          a |= (1LL << i);
        }
      }
    } else {
      if (c & (1LL << i)) {
        if (b & (1LL << i)) {
          a |= (1LL << i);
        }
      }
    }
  }
  // cout << (a | b) << " " << (a & c) << "\n";
  if (((a | b) - (a & c)) == d) {
    cout << a << "\n";
  } else {
    cout << -1 << "\n";
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
