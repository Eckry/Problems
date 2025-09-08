#include <bits/stdc++.h>
#include <sys/types.h>

using namespace std;

#define ll long long

#define optimize()                                                             \
  cin.tie(0);                                                                  \
  cin.sync_with_stdio(0);                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cout.tie(0);

struct SegTree {
  vector<ll> sg;
  ll N;

  SegTree(ll n) {
    N = 1;
    while (N < n) {
      N <<= 1;
    }
    sg.resize(N << 1);
  }

  void build(ll v, ll tl, ll tr, vector<ll> &a) {
    if (tl == tr) {
      sg[v] = a[tl];
    } else {
      ll tm = (tr + tl) / 2;
      build(v << 1, tl, tm, a);
      build(v << 1 | 1, tm + 1, tr, a);
      sg[v] = max(sg[v << 1], sg[v << 1 | 1]);
    }
  }

  ll query(ll v, ll tl, ll tr, ll val, ll pos) {
    if (sg[v] < val || pos < tl)
      return -1;
    if (tl == tr) {
      if (sg[v] >= val && pos != tl) {
        return tl;
      } else {
        return -1;
      }
    }
    ll tm = (tl + tr) / 2;
    ll right = query(v << 1 | 1, tm + 1, tr, val, pos);
    if (right != -1)
      return right;
    return query(v << 1, tl, tm, val, pos);
  }
};

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> b(n);
  for (auto &c : a)
    cin >> c;
  for (auto &c : b)
    cin >> c;
  SegTree sg(n);
  sg.build(1, 0, n - 1, a);
  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    if (a[i] == b[i])
      ans += (i + 1) * (n - i);
    else {
      ll prev = sg.query(1, 0, n - 1, max(b[i], a[i]), i);
      if (prev == -1) {
        // cout << 0 << "\n";
        continue;
      }
      ans += (prev + 1) * (n - i);
      // cout << prev << " " << (prev + 1) * (n - i) << "\n";
      // cout << prev << " ";
    }
  }
  // cout << "\n";
  cout << ans << "\n";
}

int main() {
  optimize();
  int T;
  cin >> T;
  while (T--)
    solve();
}
