#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> q(n);
  vector<ll> r(n);
  for (auto &c : q)
    cin >> c;
  for (auto &c : r)
    cin >> c;

  sort(q.begin(), q.end());
  sort(r.begin(), r.end(), greater<ll>());
  ll i = 0;
  ll j = 0;
  ll ans = 0;
  while (i < n && j < n) {
    ll y = r[i];
    ll x = y + 1;
    ll need = y + x * q[j];
    // cout << i << " " << j << "\n";
    if (need <= k) {
      ans++;
      i++;
      j++;
    } else {
      i++;
    }
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
