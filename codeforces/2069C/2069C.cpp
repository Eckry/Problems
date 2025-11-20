#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll MOD = 998244353;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;
  vector<ll> dp(4, 0);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    if (a[i] == 2) {
      dp[a[i]] = dp[a[i]] * 2 % MOD;
    }
    dp[a[i]] = (dp[a[i]] + dp[a[i] - 1]) % MOD;
  }
  cout << dp[3] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
