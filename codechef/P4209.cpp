#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int one = 0;
  int alone = 0;
  int ans = 0;

  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      if (one == 3 || one == 2) {
        ans = 1;
      }
      if (one)
        alone++;
      one = 0;
    } else {
      one++;
    }
  }
  if (one == 3 || one == 2) {
    ans = 1;
  }
  if (one)
    alone++;
  if (!ans || alone > 1) {
    cout << "Yes" << "\n";
  } else {
    cout << "No" << "\n";
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
