#include <bits/stdc++.h>
#include <numeric>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;
  vector<ll> cost(n);
  for (auto &c : cost)
    cin >> c;

  vector<ll> dp(n + 1, 0);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    dp[i] = cost[i];
    ll mx = 0;
    for (int j = 0; j < i; j++) {
      if (a[j] <= a[i]) {
        mx = max(mx, dp[j]);
      }
    }
    dp[i] += mx;
    ans = max(ans, dp[i]);
  }
  ll sm = accumulate(cost.begin(), cost.end(), 0LL);
  cout << sm - ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
