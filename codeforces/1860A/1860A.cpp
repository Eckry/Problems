#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  cin >> s;
  if (s == "()") {
    cout << "NO" << "\n";
    return;
  }
  if (s == ")(") {
    cout << "YES" << "\n";
    cout << "(())" << "\n";
    return;
  }
  cout << "YES" << "\n";
  int n = s.size();
  for (int i = 0; i < n - 1; i++) {
    if ((s[i] == '(' && s[i + 1] == '(') || (s[i] == ')' && s[i + 1] == ')')) {
      for (int i = 0; i < n; i++) {
        cout << "()";
      }
      cout << "\n";
      return;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << '(';
  }
  for (int i = 0; i < n; i++) {
    cout << ')';
  }
  cout << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}
