#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;
  string s;
  cin >> s;
  int mx;
  int mn;
  for (int i = 0; i < n; i++) {
    if (a[i] == n)
      mx = i;
    if (a[i] == 1)
      mn = i;
  }
  if (s[mn] == '1' || s[mx] == '1' || s[0] == '1' || s[n - 1] == '1') {
    cout << "-1\n";
    return;
  }
  cout << 5 << "\n";
  cout << 1 << " " << n << "\n";
  cout << 1 << " " << mn + 1 << "\n";
  cout << 1 << " " << mx + 1 << "\n";
  cout << mx + 1 << " " << n << "\n";
  cout << mn + 1 << " " << n << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
