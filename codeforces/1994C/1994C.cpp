#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n, x;
  cin >> n >> x;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;

  vector<ll> pref(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + a[i - 1];
  }
  vector<ll> dp(n + 1, 0);
  for (int i = n - 1; i >= 0; i--) {
    auto j =
        lower_bound(pref.begin(), pref.end(), x + pref[i] + 1) - pref.begin();
    if (j == n + 1) {
      dp[i] = n - i;
    } else {
      dp[i] = dp[j] + j - i - 1;
    }
  }
  ll ans = 0;
  ans = accumulate(dp.begin(), dp.end(), 0LL);
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
