#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  map<int, int> mp;
  if (n == 1) {
    cout << 1 << "\n";
    return;
  }
  mp[n]++;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      mp[i]++;
      if (i * i != n)
        mp[n / i]++;
    }
  }
  map<int, int> dp;

  dp[1] = 1;
  for (auto [key, val] : mp) {
    for (auto [key2, val2] : mp) {
      if (key2 % key == 0)
        dp[key2] += dp[key2 / key];
    }
  }
  cout << dp[n] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
