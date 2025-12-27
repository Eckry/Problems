#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  int ok = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'Y') {
      ok++;
    }
  }
  if (ok >= 2)
    cout << "NO\n";
  else
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
