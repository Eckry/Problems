#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  vector<ll> b(n);
  for (auto &c : a)
    cin >> c;
  for (auto &c : b)
    cin >> c;

  ll ans = 0;
  map<ll, ll> mp;
  ll num = 0;
  ll diff = 0;
  sort(a.begin(), a.end(), greater<>());
  for (int i = 0; i < n; i++) {
    ans += b[i] + a[i];
    mp[b[i]]++;
    if (mp[b[i]] > n) {
      num = b[i];
      diff = mp[a[i]] - n;
    }
  }
  for (int i = 0; i < n; i++) {
    mp[a[i]]++;
    if (mp[a[i]] > n) {
      num = a[i];
      diff = mp[a[i]] - n;
    }
  }
  cout << ans - (diff * num * 2LL) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
