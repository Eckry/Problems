#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll exp(ll a, ll b) {
  if (b < 0)
    return 0;
  ll res = 1;
  while (b) {
    if (b & 1) {
      res *= a;
    }
    a *= a;
    b >>= 1;
  }
  return res;
}

void solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> cost(20);
  for (ll i = 0; i < 20; i++) {
    cost[i] = exp(3, i + 1) + i * exp(3, i - 1);
  }
  vector<ll> us;
  ll min_k = 0;
  while (n) {
    us.push_back(n % 3);
    min_k += n % 3;
    n /= 3;
  }
  if (min_k > k) {
    cout << -1 << "\n";
    return;
  }
  int m = us.size();
  k -= min_k;
  k /= 2;
  for (int i = m - 1; i > 0; i--) {
    if (us[i] <= k) {
      k -= us[i];
      us[i - 1] += 3 * us[i];
      us[i] = 0;
    } else {
      us[i - 1] += k * 3;
      us[i] -= k;
      break;
    }
  }
  ll ans = 0;
  for (int i = 0; i < m; i++) {
    ans += cost[i] * us[i];
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
