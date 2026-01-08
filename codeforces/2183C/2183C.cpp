#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n, m, k;
  cin >> n >> m >> k;
  if (k > (n + 1) / 2) {
    k = n - k + 1;
  }
  ll j = n;
  ll best = 1;
  while (j != k) {
    // cout << j << " ";
    ll t = m;
    ll ans = 1;
    ll acc = 0;
    t -= j - k;
    if (t < 0) {
      // best = max(best, ans + t + j - k);
      // cout << "Finished: " << ans + t + j - k << "\n";
      j--;
      continue;
    }
    acc += j - k;
    ans++;
    best = max(ans, best);
    t -= j - k - 1;
    if (t < 0) {
      best = max(best, ans + t + j - k - 1);
      // cout << "Finished: " << ans + t + j - k - 1 << "\n";
      j--;
      continue;
    }
    ans += j - k - 1;
    t -= min(k - 1, acc);
    if (t < 0) {
      best = max(best, ans + t + min(k - 1, acc));
      // cout << "Finished: " << ans + t + min(k - 1, acc) << "\n";
      j--;
      continue;
    }
    j--;
    ans += min(k - 1, acc);
    // cout << "Finished: " << ans << "\n";
    best = max(best, ans);
  }
  cout << best << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
