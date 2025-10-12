#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                                                             \
  cin.tie(0);                                                                  \
  cin.sync_with_stdio(0);                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cout.tie(0);

const int MOD = 998244353;

void solve() {

  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (auto &c : a)
    cin >> c;
  for (auto &c : b)
    cin >> c;
  vector<ll> dp(n + 1, 0);
  dp[0] = 1;
  dp[1] = 2;
  for (int i = 1; i < n; i++) {
    if (b[i] >= b[i - 1] && a[i] >= a[i - 1] && b[i] >= a[i - 1] &&
        a[i] >= b[i - 1])
      dp[i + 1] = (dp[i + 1] + dp[i] * 2) % MOD;
    else if (b[i] >= a[i - 1] && a[i] >= b[i - 1])
      dp[i + 1] = (dp[i + 1] + dp[i]) % MOD;
    else if (a[i] >= a[i - 1] && b[i] >= b[i - 1])
      dp[i + 1] = (dp[i + 1] + dp[i]) % MOD;
    else {
      cout << 1 << "\n";
      return;
    }
  }
  // for (auto c : dp)
  //   cout << c << " ";
  // cout << "\n";
  cout << dp[n] % MOD << "\n";
}

int main() {
  optimize() int T;
  cin >> T;
  while (T--)
    solve();
}
