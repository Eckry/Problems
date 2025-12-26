#include <bits/stdc++.h>

using namespace std;

#define ll long long

int check(string &a, string &b) {
  int n = a.size();
  int m = b.size();
  for (int i = 0; i < min(n, m); i++) {
    if (a[i] < b[i])
      return 1;
    if (a[i] > b[i])
      return 0;
  }
  if (n < m)
    return 1;
  else
    return 0;
}

void solve() {
  int n;
  cin >> n;
  vector<string> a(n);
  for (auto &c : a)
    cin >> c;

  string s = a[0];
  for (int i = 1; i < n; i++) {
    int m = a[i].size();
    string op1 = s + a[i];
    string op2 = a[i] + s;
    if (check(op1, op2)) {
      s += a[i];
    } else {
      s = a[i] + s;
    }
  }
  cout << s << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
