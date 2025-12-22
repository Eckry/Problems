#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;

  map<ll, ll> mp;
  ll sm = 0;
  mp[0] = 1;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    sm += a[i];
    if (mp.find(sm) != mp.end()) {
      ans++;
      mp.clear();
      sm = 0;
      mp[0] = 1;
    } else {
      mp[sm] = 1;
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
