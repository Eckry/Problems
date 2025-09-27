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
  vector<int> ans(2 * n);
  for(int i = 0 ;i<n;i++) {
    ans[i] = n - i;
  }
  ans[n] = n;
  for(int i = 0; i<n - 1;i++) {
    ans[i + n + 1] = i + 1;
  }
  for (auto c : ans)
    cout << c << " ";
  cout << "\n";
}

int main() {
  optimize();
  int T;
  cin >> T;
  while (T--)
    solve();
}
