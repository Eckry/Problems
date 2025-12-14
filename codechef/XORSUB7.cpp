#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;
  ll ans = 0;
  vector<ll> dp(n, 1);
  sort(a.begin(), a.end(), greater<ll>());
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i + 1; j < n; j++) {
      if (abs(a[i] - a[j]) == (a[i] ^ a[j])) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    ans = max(ans, dp[i]);
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
