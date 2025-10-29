#include <bits/stdc++.h>

using namespace std;

#define ll long long

int check(int k, int l, vector<int> &a, int n, int x) {
  vector<int> valid(n, 1);
  vector<pair<int, int>> seg;
  for (int i = 0; i < n; i++) {
    seg.push_back({max(0, a[i] - l + 1), min(x, a[i] + l - 1)});
  }
  ll res = x + 1;
  for (int i = 0; i < seg.size() - 1; i++) {
    res -= seg[i].second - seg[i].first + 1;
    if (seg[i].second >= seg[i + 1].first) {
      res += seg[i].second - seg[i + 1].first + 1;
    }
  }
  res -= seg[seg.size() - 1].second - seg[seg.size() - 1].first + 1;
  // cout << res << " res\n";
  if (res < k)
    return 0;
  return 1;
}

vector<int> generate(int l, vector<int> &a, int k, int n) {
  vector<int> res;
  if (l == 0) {
    for (int i = 0; i < k; i++) {
      res.push_back(i);
    }
    return res;
  }
  int pos = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    ll left = a[i] - l + 1;
    ll right = a[i] + l - 1;
    while (pos < left) {
      res.push_back(pos);
      pos++;
      cnt++;
      if (cnt >= k)
        return res;
    }
    pos = right + 1;
    // cout << pos << "\n";
    if (cnt >= k)
      return res;
  }
  while (cnt < k) {
    res.push_back(pos);
    pos++;
    cnt++;
  }
  return res;
}

void solve() {
  int n, k, x;
  cin >> n >> k >> x;

  vector<int> a(n);
  for (auto &c : a)
    cin >> c;
  sort(a.begin(), a.end());
  ll r = 1e9 + 1;
  ll l = 0;
  ll ans = 0;
  while (l <= r) {
    ll mid = (l + r) >> 1;
    // cout << mid << "\n";
    if (check(k, mid, a, n, x)) {
      l = mid + 1;
      ans = mid;
    } else {
      r = mid - 1;
    }
  }
  vector<int> lol = generate(ans, a, k, n);
  for (auto c : lol)
    cout << c << " ";
  cout << "\n";
  // cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
