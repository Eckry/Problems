#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;

  if (m > n / 2) {
    cout << -1 << "\n";
    return;
  }
  if (m == 0) {
    vector<ll> idx(n);
    iota(idx.begin(), idx.end(), 0LL);
    sort(idx.begin(), idx.end(), [&](ll x, ll y) { return a[x] < a[y]; });
    ll target = a[idx[n - 1]];
    ll sm = 0;
    int j = n - 2;
    // for (auto v : idx) {
    //   cout << v << " ";
    // }
    // cout << "\n";
    vector<pair<ll, ll>> ans;
    for (int i = n - 2; i >= 0; i--) {
      int id = idx[i];
      j = i;
      sm += a[id];
      if (sm >= target) {
        break;
      }
    }
    if (sm < target) {
      cout << -1 << "\n";
      return;
    }
    // cout << j << "\n";
    for (int i = 1; i <= j; i++) {
      ans.push_back({idx[i] + 1, idx[i - 1] + 1});
    }
    for (int i = j + 1; i < n - 1; i++) {
      ans.push_back({idx[i] + 1, idx[n - 1] + 1});
    }
    ans.push_back({idx[n - 1] + 1, idx[j] + 1});
    cout << ans.size() << "\n";
    for (auto [v, u] : ans) {
      cout << v << " " << u << "\n";
    }

    return;
  }

  vector<int> idx(n);
  iota(idx.begin(), idx.end(), 0);
  sort(idx.begin(), idx.end(), [&](int x, int y) { return a[x] < a[y]; });
  // for (auto c : idx) {
  //   cout << c << " ";
  // }
  // cout << "\n";

  int need = n - m;
  int cnt = 0;
  int temp = n;
  while (m) {
    if (need == n / 2)
      break;
    need--;
    cnt++;
    n--;
  }
  vector<pair<int, int>> ans;
  for (int i = 0; i < cnt; i++) {
    ans.push_back({idx[i + 1] + 1, idx[i] + 1});
  }
  for (int i = cnt; i < temp - 1; i += 2) {
    ans.push_back({idx[i + 1] + 1, idx[i] + 1});
  }
  cout << ans.size() << "\n";
  for (auto [v, u] : ans) {
    cout << v << " " << u << "\n";
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
