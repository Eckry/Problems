#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<vector<int>> odd(n + 1, vector<int>(26, 0));
  vector<vector<int>> even(n + 1, vector<int>(26, 0));
  vector<vector<int>> oddsuf(n + 1, vector<int>(26, 0));
  vector<vector<int>> evensuf(n + 1, vector<int>(26, 0));
  for (int i = 0; i < n; i++) {
    odd[i + 1] = odd[i];
    even[i + 1] = even[i];
    int bitmask = s[i] - 'a';
    if (i % 2 == 0) {
      odd[i + 1][bitmask]++;
    } else {
      even[i + 1][bitmask]++;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    oddsuf[i] = oddsuf[i + 1];
    evensuf[i] = evensuf[i + 1];
    int bitmask = s[i] - 'a';
    if (i % 2 == 0) {
      oddsuf[i][bitmask]++;
    } else {
      evensuf[i][bitmask]++;
    }
  }

  if (s.size() & 1) {
    int idx = 0;
    int mn = 10000000;
    for (int i = 0; i < n; i++) {
      int maxodd = 0;
      for (int j = 0; j < 26; j++) {
        maxodd = max(maxodd, odd[i][j] + evensuf[i + 1][j]);
      }
      int maxeven = 0;
      for (int j = 0; j < 26; j++) {
        // if (i == 2) {
        //   // cout << even[i][j] << " " << oddsuf[i + 1][j] << " xdd\n";
        // }
        maxeven = max(maxeven, even[i][j] + oddsuf[i + 1][j]);
      }

      int op = n - maxodd - maxeven - 1;
      if (mn > op) {
        idx = i;
        mn = op;
      }
    }
    cout << mn + 1 << "\n";
  } else {
    int mxeven = 0;
    int mxodd = 0;
    for (int i = 0; i < 26; i++) {
      mxeven = max(mxeven, even[n][i]);
      mxodd = max(mxodd, odd[n][i]);
    }
    cout << n - mxeven - mxodd << "\n";
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
