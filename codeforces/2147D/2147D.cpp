#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                                                             \
  cin.tie(0);                                                                  \
  cin.sync_with_stdio(0);                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cout.tie(0);

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<ll, ll> mp;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;
    if (a[i] & 1)
      a[i]--;
  }

  vector<pair<ll, ll>> nums;
  for (auto c : mp) {
    if (c.first & 1) {
      nums.push_back({c.first, c.second});
    }
  }
  sort(nums.begin(), nums.end(),
       [&](pair<ll, ll> x, pair<ll, ll> y) { return x.second > y.second; });

  int flg = 0;
  ll alice = 0;
  ll bob = 0;

  for (int i = 0; i < nums.size(); i++) {
    if (flg) {
      bob += nums[i].second;
      flg = 0;
    } else {
      alice += nums[i].second;
      flg = 1;
    }
  }

  ll sm = 0;

  for (int i = 0; i < n; i++) {
    // cout << a[i] << " ";
    sm += a[i];
  }

  alice += sm / 2;
  bob += sm / 2;
  cout << alice << " " << bob << "\n";
}

int main() {
  optimize();
  int T;
  cin >> T;
  while (T--)
    solve();
}
