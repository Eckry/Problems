#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n, p;
  cin >> n >> p;
  vector<ll> a(n);
  vector<ll> b(n);
  for (auto &c : a)
    cin >> c;
  for (auto &c : b)
    cin >> c;
  int l = n - 1;
  vector<int> idx(n);
  iota(idx.begin(), idx.end(), 0);
  sort(idx.begin(), idx.end(), [&](int x, int y) { return b[x] < b[y]; });
  ll ans = p;
  int j = 0;
  while (j < n && l > 0 && b[idx[j]] < p) {
    int i = idx[j];
    while (l && a[i]) {
      a[i]--;
      l--;
      ans += b[i];
    }
    j++;
  }
  cout << ans + p * l << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
