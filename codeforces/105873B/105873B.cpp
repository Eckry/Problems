#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  ll n;
  cin >> n;
  vector<vector<ll>> a(n, vector<ll>(n));
  for (auto &vec : a)
    for (auto &c : vec) {
      cin >> c;
    }
  ll ans = 0;

  vector<pair<ll, ll>> start = {{0, 0},
                                {
                                    0,
                                    n - 1,
                                },
                                {n - 1, 0},
                                {n - 1, n - 1}};

  vector<pair<ll, ll>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  ll cnt = 0;
  vector<vector<ll>> m(n, vector<ll>(n, 0));
  for (auto init : start) {
    cnt++;
    ll mx = 0;
    ll i = init.first;
    ll j = init.second;
    // cout << i << " " << j << " " << directions[0].first << " "
    //      << directions[0].second << "\n";
    ll flg = 0;
    ll lol = 1;
    mx = max(mx + a[i][j], a[i][j]);
    ans = max(ans, mx);
    while (!flg) {
      m[i][j] = cnt;
      for (auto dir : directions) {
        if (lol == n * n) {
          flg = 1;
          break;
        }
        if (i + dir.first >= n)
          continue;
        if (i + dir.first <= -1)
          continue;
        if (j + dir.second >= n)
          continue;
        if (j + dir.second <= -1)
          continue;
        if (m[i + dir.first][j + dir.second] == cnt)
          continue;
        i += dir.first;
        j += dir.second;
        while (i >= 0 && j >= 0 && i < n && j < n && m[i][j] != cnt) {
          m[i][j] = cnt;
          mx = max(mx + a[i][j], a[i][j]);
          ans = max(ans, mx);
          i += dir.first;
          j += dir.second;
          lol++;
        }
        i -= dir.first;
        j -= dir.second;
      }
    }
  }
  start = {{0, 0},
           {
               0,
               n - 1,
           },
           {n - 1, 0},
           {n - 1, n - 1}};

  directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  m = vector<vector<ll>>(n, vector<ll>(n, 0));
  for (auto init : start) {
    cnt++;
    ll i = init.first;
    ll j = init.second;
    ll flg = 0;
    ll lol = 1;
    ll mx = 0;
    // cout << i << " " << j << " " << directions[0].first << " "
    //      << directions[0].second << "\n";
    mx = max(mx + a[i][j], a[i][j]);
    ans = max(ans, mx);
    while (!flg) {
      m[i][j] = cnt;
      for (auto dir : directions) {
        if (lol == n * n) {
          flg = 1;
          break;
        }
        if (i + dir.first >= n)
          continue;
        if (i + dir.first <= -1)
          continue;
        if (j + dir.second >= n)
          continue;
        if (j + dir.second <= -1)
          continue;
        if (m[i + dir.first][j + dir.second] == cnt)
          continue;
        i += dir.first;
        j += dir.second;
        while (i >= 0 && j >= 0 && i < n && j < n && m[i][j] != cnt) {
          mx = max(mx + a[i][j], a[i][j]);
          ans = max(ans, mx);
          m[i][j] = cnt;
          i += dir.first;
          j += dir.second;
          lol++;
        }
        i -= dir.first;
        j -= dir.second;
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  T = 1;
  while (T--)
    solve();
}
