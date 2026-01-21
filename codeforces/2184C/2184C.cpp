#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll k;
ll ans;
map<ll, ll> dp;
const ll INF = 1e9 + 100;

ll dfs(ll v, ll p) {
  if (dp.find(v) != dp.end()) {
    return dp[v];
  }
  if (v < k) {
    return dp[v] = INF;
  }
  if (v == k)
    return dp[v] = p;
  ll l = v / 2;
  ll r = (v + 1) / 2;
  ll ans = dfs(l, p + 1);
  if (l != r)
    ans = min(ans, dfs(r, p + 1));
  return dp[v] = ans;
}

void solve() {
  ll n;
  ans = 1000000000LL;
  cin >> n >> k;
  dp = map<ll, ll>();
  ll ans = dfs(n, 0);
  if (ans == INF)
    cout << -1 << "\n";
  else
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
