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

  vector<ll> dp(n + 1, 0);
  vector<ll> acc(100001, 0);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    dp[i + 1] = (dp[i] + acc[a[i]]) % MOD;
    acc[a[i]] = (acc[a[i]] + dp[i]) % MOD;
  }
  // for (int i = 0; i <= n; i++) {
  //   cout << dp[i] << " ";
  // }
  // cout << "\n";
  cout << dp[n] % MOD << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  T = 1;
  while (T--)
    solve();
}
