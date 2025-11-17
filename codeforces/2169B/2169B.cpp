#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  string s;
  cin >> s;

  int n = s.size();
  if (n == 1) {
    cout << 1 << "\n";
    return;
  }
  if (s[0] == '>' && s[n - 1] == '<') {
    cout << -1 << "\n";
    return;
  }
  if (s[0] == s[n - 1] && s[0] == '*') {
    cout << -1 << "\n";
    return;
  }
  int ok = 0;
  for (int i = 1; i < n; i++) {
    if (s[i] == s[i - 1] && s[i] == '*') {
      ok = 1;
    }
    if (s[i] == '*' && s[i - 1] == '>')
      ok = 1;
    if (s[i] == '<' && s[i - 1] == '*') {
      ok = 1;
    }
    if (s[i] == '<' && s[i - 1] == '>')
      ok = 1;
  }
  if (ok) {
    cout << -1 << "\n";
    return;
  }
  int i = 0;
  while (i < n && s[i] == '<')
    i++;
  int j = i;
  while (j < n && s[j] == '*')
    j++;
  int k = j;
  while (k < n && s[k] == '>')
    k++;
  // cout << j << " " << k << " ";
  cout << max(j, k - j + (j != i)) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
