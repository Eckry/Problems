#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                                                             \
  cin.tie(0);                                                                  \
  cin.sync_with_stdio(0);                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cout.tie(0);

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  for (auto &c : a)
    cin >> c;
  sort(a.begin(), a.end());
  vector<ll> sm(m + 1, 0);
  sm[m] = 0;
  for (int i = m - 1; i >= 0; i--) {
    if (a[i] >= n)
      a[i] = n - 1;
    sm[i] = sm[i + 1] + a[i];
  }
  ll ans = 0;
  for (int i = 0; i < m - 1; i++) {
    ll x = n - a[i];
    ll idx = lower_bound(a.begin() + i + 1, a.end(), x) - a.begin();
    ans += (a[i] - n + 1) * (m - idx) + sm[idx];
  }
  cout << ans * 2 << "\n";
}

int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
}
