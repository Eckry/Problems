#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ones = 0;
  int zeros = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1')
      ones++;
    else
      zeros++;
    if (zeros <= ones)
      ans++;
  }
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
