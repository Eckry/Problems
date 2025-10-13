#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                                                             \
  cin.tie(0);                                                                  \
  cin.sync_with_stdio(0);                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cout.tie(0);

const ll MOD = 1e9 + 7;

struct Node {
  ll sm;
  ll smsq;
  ll lazy;
};

struct SegTree {
  vector<Node> sg;
  int N;
  SegTree(int n) {
    N = 1;
    while (N < n)
      N <<= 1;
    sg.resize(N << 1);
  }

  void build(int v, int tl, int tr, vector<ll> &a) {
    if (tl == tr) {
      sg[v].sm = a[tl] % MOD;
      sg[v].smsq = (a[tl] * a[tl]) % MOD;
      sg[v].lazy = 0;
    } else {
      int tm = (tl + tr) >> 1;
      build(v << 1, tl, tm, a);
      build(v << 1 | 1, tm + 1, tr, a);
      sg[v].sm = (sg[v << 1].sm + sg[v << 1 | 1].sm) % MOD;
      sg[v].smsq = (sg[v << 1].smsq + sg[v << 1 | 1].smsq) % MOD;
      sg[v].lazy = 0;
    }
  }

  void apply_add(int v, int tl, int tr, ll x) {
    ll len = tr - tl + 1;
    ll term1 = (2LL * x) % MOD;
    term1 = (term1 * sg[v].sm) % MOD;
    ll term2 = (x * x) % MOD;
    term2 = (term2 * len) % MOD;
    sg[v].smsq = (sg[v].smsq + term1 + term2) % MOD;
    sg[v].sm = (sg[v].sm + (x * len) % MOD) % MOD;
    sg[v].lazy = (sg[v].lazy + x) % MOD;
  }

  void push(int v, int tl, int tr) {
    if (sg[v].lazy != 0 && tl != tr) {
      int tm = (tl + tr) >> 1;
      ll x = sg[v].lazy;
      apply_add(v << 1, tl, tm, x);
      apply_add(v << 1 | 1, tm + 1, tr, x);
      sg[v].lazy = 0;
    }
  }

  void update(int v, int tl, int tr, int l, int r, int x) {
    if (l > r)
      return;
    if (l == tl && r == tr) {
      apply_add(v, tl, tr, x);
    } else {
      int tm = (tl + tr) >> 1;
      push(v, tl, tr);
      update(v << 1, tl, tm, l, min(r, tm), x);
      update(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, x);
      sg[v].smsq = (sg[v << 1].smsq + sg[v << 1 | 1].smsq) % MOD;
      sg[v].sm = (sg[v << 1].sm + sg[v << 1 | 1].sm) % MOD;
    }
  }

  ll query(int v, int tl, int tr, int l, int r) {
    if (l > r)
      return 0;
    if (l == tl && r == tr) {
      return sg[v].smsq % MOD;
    } else {
      push(v, tl, tr);
      int tm = (tl + tr) >> 1;
      return (query(v << 1, tl, tm, l, min(r, tm)) +
              query(v << 1 | 1, tm + 1, tr, max(tm + 1, l), r)) %
             MOD;
    }
  }
};

void solve() {
  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;
  SegTree sg(n);
  sg.build(1, 0, n - 1, a);
  while (q--) {
    char query;
    cin >> query;
    if (query == 'q') {
      ll l, r;
      cin >> l >> r;
      l--;
      r--;
      cout << sg.query(1, 0, n - 1, l, r) % MOD << "\n";
    } else {
      ll l, r, x;
      cin >> l >> r >> x;
      l--;
      r--;
      x = (x + MOD) % MOD;
      sg.update(1, 0, n - 1, l, r, x);
    }
  }
}

int main() {
  optimize();
  int T;
  T = 1;
  while (T--)
    solve();
}
