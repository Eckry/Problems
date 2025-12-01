#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll h, n;
  cin >> h >> n;
  vector<ll> a(n);
  vector<ll> b(n);
  for (auto &c : a)
    cin >> c;
  for (auto &c : b)
    cin >> c;
  map<ll, pair<ll, vector<ll>>> mp;
  ll sm = 0;
  for (auto c : a)
    sm += c;
  h -= sm;

  if (h <= 0) {
    cout << 1 << "\n";
    return;
  }

  set<ll> turnes;
  for (ll i = 0; i < n; i++) {
    mp[b[i] + 1].first += a[i];
    mp[b[i] + 1].second.push_back(i);
    turnes.insert(b[i] + 1);
  }

  ll ans = 2;
  while (h > 0) {
    ans = *turnes.begin();
    auto it = turnes.begin();
    h -= mp[ans].first;
    for (auto ele : mp[ans].second) {
      ll time = b[ele];
      mp[ans + time].first += a[ele];
      mp[ans + time].second.push_back(ele);
      if (turnes.find(ans + time) == turnes.end())
        turnes.insert(ans + time);
    }
    turnes.erase(it);
    if (h <= 0)
      break;
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
