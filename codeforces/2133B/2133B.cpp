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
  vector<int> g(n);
  for (auto &c : g)
    cin >> c;
  ll ans = 0;
  sort(g.begin(), g.end());
  for (int i = n - 1; i > 0; i -= 2) {
    ans += max(g[i], g[i - 1]);
    int red = min(g[i], g[i - 1]);
    g[i] -= red;
    g[i - 1] -= red;
  }
  if (n & 1) {
    ans += g[0];
  }
  cout << ans << "\n";
}

int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
}
