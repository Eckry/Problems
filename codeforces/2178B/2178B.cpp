#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  string s;
  cin >> s;
  int n = s.size();

  int ans = 0;
  if (s[0] == 'u') {
    ans++;
    s[0] = 's';
  }
  for (int i = 1; i < n - 1; i += 1) {
    if (s[i] == 'u') {
      if (s[i - 1] == 's' && s[i + 1] == 's')
        continue;
      if (s[i - 1] != 's') {
        ans++;
        s[i - 1] = 's';
      }
      if (s[i + 1] != 's') {
        ans++;
        s[i + 1] = 's';
      }
    }
  }
  if (s[n - 1] == 'u') {
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
