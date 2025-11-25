#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  if (s[0] == '0' || s[n - 1] == '0') {
    cout << -1 << "\n";
    return;
  }
  vector<int> ans(n);
  iota(ans.begin(), ans.end(), 1);

  for (int i = n - 2; i > 0; i--) {
    if (s[i] == '0') {
      swap(ans[i + 1], ans[i]);
    }
  }
  for (auto c : ans) {
    cout << c << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
