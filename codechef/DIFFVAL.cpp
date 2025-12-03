#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;
  int ones = 0;
  int zeros = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1')
      ones++;
    else
      zeros++;
  }

  vector<int> checked(n, 0);
  for (int i = 0; i < n; i++) {
    if (checked[i])
      continue;
    if (i + k >= n)
      break;
    if (!ones || !zeros) {
      cout << "NO\n";
      return;
    }
    ones--;
    checked[i + k] = 1;
    zeros--;
  }
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
