#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                                                             \
  cin.tie(0);                                                                  \
  cin.sync_with_stdio(0);                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cout.tie(0);

void solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;

  map<ll, ll> cnt;
  for (int i = 0; i < n; i++) {
    if (a[i] % k)
      cnt[k - a[i] % k]++;
  }
  // for (auto c : cnt)
  //   cout << c << " ";
  // cout << "\n";

  ll mx = 1;
  ll key = 0;
  for (auto value : cnt) {
    if (mx <= value.second) {
      key = value.first;
      mx = value.second;
    }
  }
  cout << k * (mx - 1) + key + (key != 0) << "\n";
}

int main() {
  optimize();
  int T;
  cin >> T;
  while (T--)
    solve();
}
