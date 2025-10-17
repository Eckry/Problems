#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;
  int ans = 0;
  for (auto c : a) {
    ans = max(ans, c);
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
