#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct Node {
  int pos;
  ll x;
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
      sg[v].x = a[tl];
      sg[v].pos = tl;
    } else {
      int tm = (tl + tr) / 2;
      build(v << 1, tl, tm, a);
      build(v << 1 | 1, tm + 1, tr, a);
      sg[v].x = max(sg[v << 1].x, sg[v << 1 | 1].x);
      if (sg[v << 1].x >= sg[v << 1 | 1].x) {
        sg[v].x = sg[v << 1].x;
        sg[v].pos = sg[v << 1].pos;
      } else {
        sg[v].x = sg[v << 1 | 1].x;
        sg[v].pos = sg[v << 1 | 1].pos;
      }
    }
  }

  Node query(int v, int tl, int tr, int l, int r) {
    if (l > r) {
      Node n;
      n.x = 0;
      n.pos = 10000;
      return n;
    }
    if (tl == tr) {
      return sg[v];
    }
    int tm = (tl + tr) >> 1;
    Node left = query(v << 1, tl, tm, l, min(r, tm));
    Node right = query(v << 1 | 1, tm + 1, tr, max(tm + 1, l), r);

    if (left.x >= right.x) {
      return left;
    } else {
      return right;
    }
  }

  void update(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
      sg[v].x = val;
    } else {
      int tm = (tl + tr) >> 1;
      if (pos <= tm) {
        update(v << 1, tl, tm, pos, val);
      } else {
        update(v << 1 | 1, tm + 1, tr, pos, val);
      }
      sg[v].x = max(sg[v << 1].x, sg[v << 1 | 1].x);
      if (sg[v << 1].x >= sg[v << 1 | 1].x) {
        sg[v].x = sg[v << 1].x;
        sg[v].pos = sg[v << 1].pos;
      } else {
        sg[v].x = sg[v << 1 | 1].x;
        sg[v].pos = sg[v << 1 | 1].pos;
      }
    }
  }
};

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;
  ll mn = 100000000000LL;
  ll mx = 0;
  for (int i = 0; i < n; i++) {
    mx = max(a[i], mx);
    mn = min(a[i], mn);
  }
  if (is_sorted(a.begin(), a.end())) {
    cout << "-1\n";
    return;
  }
  vector<ll> cp = a;
  sort(cp.begin(), cp.end());
  ll ans = 100000000000LL;
  for (int i = 0; i < n; i++) {
    if (cp[i] == a[i])
      continue;
    ll best = llabs(mn - a[i]);
    best = max(best, llabs(mx - a[i]));
    ans = min(ans, best);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
