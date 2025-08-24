#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define optimize()                                                             \
  cin.tie(0);                                                                  \
  cin.sync_with_stdio(0);                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cout.tie(0);

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;

  map<ll, ll> mp;
  for (int i = 0; i < n; i++) {
    mp[a[i]]++;
  }
  for (auto [key, value] : mp) {
    if (value >= 2 && mp[key + 1] >= 1 && mp[key + 2] >= 2) {
      cout << "YES" << "\n";
      return;
    }
    if (value >= 4) {
      cout << "YES" << "\n";
      return;
    }
  }

  mp.clear();
  map<ll, ll> all;
  for (int i = 0; i < n; i++) {
    all[a[i]]++;
    all[a[i] + 1]++;
    all[a[i] + 2]++;
    mp[a[i]]++;
  }

  for (auto [key, value] : all) {

    if (mp[key - 1] >= 2 && mp[key - 2] >= 2) {
      cout << "YES" << "\n";
      return;
    }
  }
  cout << "NO" << "\n";
}

int main(void) {
  optimize();
  int T;
  cin >> T;
  // T = 1;
  while (T--)
    solve();
}
