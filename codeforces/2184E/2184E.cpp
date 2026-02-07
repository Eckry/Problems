#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct DSU {
  vector<int> dsu;
  vector<int> sz;
  DSU(int n) {
    dsu.assign(n, -1);
    sz.assign(n, 1);
    for (int i = 0; i < n; i++) {
      dsu[i] = i;
    }
  }

  int find_parent(int v) {
    if (dsu[v] == v)
      return v;
    return dsu[v] = find_parent(dsu[v]);
  }

  void make_union(int v, int u) {
    u = find_parent(u);
    v = find_parent(v);
    if (u != v) {
      dsu[u] = v;
      sz[v] += sz[u];
    }
  }

  int get_sz(int v) { return sz[v]; }
};

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;

  vector<vector<int>> d(n, vector<int>());
  for (int i = 0; i < n - 1; i++) {
    int dif = abs(a[i + 1] + -a[i]);
    d[dif].push_back(i);
  }

  vector<ll> res;
  ll ans = 0;

  DSU dsu(n);
  for (int k = n - 1; k > 0; k--) {
    // cout << "Diff: " << k << "\n";
    for (auto i : d[k]) {
      // cout << i << "\n";
      int v = i;
      int u = i + 1;
      int pu = dsu.find_parent(u);
      int pv = dsu.find_parent(v);
      // cout << pv << " " << pu << "\n";
      if (pu != pv) {
        ll szpv = dsu.get_sz(pv);
        ll szpu = dsu.get_sz(pu);
        // cout << "Parents size: " << szpv << " " << szpu << "\n";
        ans -= szpv * (szpv - 1) / 2;
        ans -= szpu * (szpu - 1) / 2;
        dsu.make_union(v, u);
        ll szall = dsu.get_sz(pv);
        // cout << szall << " szall\n";
        ans += szall * (szall - 1) / 2;
      }
    }
    res.push_back(ans);
    // cout << ans << "\n";
    // cout << ans << " ";
  }
  reverse(res.begin(), res.end());
  for (auto c : res) {
    cout << c << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
