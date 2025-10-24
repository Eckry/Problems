#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll calc(vector<ll> a, vector<ll> b, ll n, ll m) {
  map<ll, ll> mp;
  sort(b.begin(), b.end(), greater<>());
  sort(a.begin(), a.end(), greater<>());
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += a[i];
    mp[a[i]]++;
  }
  int cnt = 0;
  for (int i = 0; i < m; i++) {
    if (mp[b[i]] < n) {
      ans += b[i];
      mp[b[i]]++;
      cnt++;
    }
    if (cnt >= n) {
      break;
    }
  }
  mp.clear();
  for (int i = 0; i < n; i++) {
    mp[a[i]]++;
  }
  ll diff = 0;
  ll num = -1;
  for (int i = 0; i < m; i++) {
    mp[b[i]]++;
    if (mp[b[i]] >= m) {
      num = b[i];
      diff = mp[b[i]] - m;
    }
  }
  // cout << num << " " << diff << "\n";
  return ans - diff * num;
}

void solve() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  vector<ll> b(m);
  for (auto &c : a)
    cin >> c;
  for (auto &c : b)
    cin >> c;

  if (n < m) {
    cout << calc(a, b, n, m) << "\n";

  } else {
    cout << calc(b, a, m, n) << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
