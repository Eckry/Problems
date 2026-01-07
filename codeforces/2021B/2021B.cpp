#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n, x;
  cin >> n >> x;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;

  map<ll, ll> mp;
  for (auto c : a) {
    mp[c]++;
  }
  ll mex = 0;
  while (mp[mex]) {
    mp[mex + x] += mp[mex] - 1;
    mex++;
  }
  cout << mex << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
