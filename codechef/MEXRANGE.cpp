#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                                                             \
  cin.tie(0);                                                                  \
  cin.sync_with_stdio(0);                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cout.tie(0);

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> ans(n + 1);
  iota(ans.begin(), ans.end(), 0);
  for (int i = 2; i <= n; i++) {
    if (s[i] == '0') {
      int temp = ans[i - 1];
      ans[i - 1] = ans[i];
      ans[i] = temp;
    }
  }
  for (int i = 0; i<n; i++)
    cout << ans[i] << " ";
  cout << "\n";
}

int main() {
  optimize();
  int T;
  cin >> T;
  while (T--)
    solve();
}
