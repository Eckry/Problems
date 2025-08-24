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
  vector<int> h(n);
  for (auto &c : h)
    cin >> c;
  vector<ll> dp(n + 1);
  dp[0] = 0;
  dp[1] = h[0];
  for (int i = 2; i <= n; i++) {
    dp[i] = min(dp[i - 1] + h[i - 1] - 1,
                dp[i - 2] + h[i - 2] + max(0, h[i - 1] - i + 1));
  }
  cout << dp[n] << "\n";
}

int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
}
