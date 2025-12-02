#include <bits/stdc++.h>
#include <pthread.h>

using namespace std;

#define ll long long

const ll INF = 1e15 + 1;

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;

  vector<ll> prefodd(n, 0);
  vector<ll> prefeven(n, 0);

  prefodd[0] = -1 - 2 * a[0];
  prefeven[0] = -INF;
  for (int i = 1; i < n; i++) {
    prefeven[i] = prefeven[i - 1];
    prefodd[i] = prefodd[i - 1];
    if (i & 1) {
      prefeven[i] = max(prefeven[i], -i - 1 + 2 * a[i]);
    } else {
      prefodd[i] = max(prefodd[i], -i - 1 - 2 * a[i]);
    }
  }
  // for (auto c : prefodd) {
  //   cout << c << " ";
  // }
  // cout << "\n";
  // for (auto c : prefeven) {
  //   cout << c << " ";
  // }
  // cout << "\n";
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (i & 1) {
      ans -= a[i];
    } else {
      ans += a[i];
    }
  }

  ll res = ans;
  // cout << res << " ";
  for (ll i = 1; i < n; i++) {
    if (i & 1) {
      res = max(res, ans + i - 1);
      res = max(res, ans + i + 1 + 2 * a[i] + prefodd[i - 1]);
    } else {
      res = max(res, ans + i);
      res = max(res, ans + i + 1 - 2 * a[i] + prefeven[i - 1]);
    }
    // cout << res << " ";
  }
  // cout << "\n";
  cout << res << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
