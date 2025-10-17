#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<int> ans;

  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      ans.push_back(i + 1);
    }
  }
  cout << ans.size() << "\n";
  for (auto c : ans)
    cout << c << " ";
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
