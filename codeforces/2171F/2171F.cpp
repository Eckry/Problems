
#include <bits/stdc++.h>

using namespace std;

#define ll long long
vector<int> dsu;

int find_par(int v) {
  if (dsu[v] == v)
    return v;
  return dsu[v] = find_par(dsu[v]);
}

void make_union(int v, int u) {
  int paru = find_par(u);
  int parv = find_par(v);
  if (paru != parv)
    dsu[parv] = dsu[paru];
}

void solve() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (auto &c : p)
    cin >> c;

  dsu = vector<int>(n);
  for (int i = 0; i < n; i++) {
    dsu[i] = i;
  }
  int mx = 0;
  int mn = 0;
  for (int i = 0; i < n; i++) {
    if (p[i] == 1)
      mn = i;
    if (p[i] == n)
      mx = i;
  }
  if (mx > mn) {
    cout << "Yes\n";
    for (int i = 0; i < mx; i++) {
      cout << p[i] << " " << p[mx] << "\n";
    }
    for (int i = mx + 1; i < n; i++) {
      cout << p[i] << " " << p[mn] << "\n";
    }
    return;
  }
  if (p[0] == n || p[n - 1] == 1) {
    cout << "No\n";
    return;
  }
  vector<pair<int, int>> edges;

  int leftmn = 0;
  int rightmx = mn + 1;
  for (int i = 0; i < mx; i++) {
    if (p[i] < p[leftmn]) {
      leftmn = i;
    }
  }

  for (int i = mn + 1; i < n; i++) {
    if (p[i] > p[rightmx]) {
      rightmx = i;
    }
  }

  for (int i = 0; i < mx; i++) {
    make_union(i, mx);
    edges.push_back({p[i], p[mx]});
  }
  for (int i = mn + 1; i < n; i++) {
    make_union(i, mn);
    edges.push_back({p[i], p[mn]});
  }

  if (p[leftmn] < p[rightmx]) {
    make_union(leftmn, rightmx);
    edges.push_back({p[leftmn], p[rightmx]});
  }

  int minchecked = -1;
  for (int i = mx + 1; i < mn; i++) {
    if (p[i] > p[leftmn]) {
      if (minchecked == -1)
        minchecked = i;
      if (p[minchecked] > p[i])
        minchecked = i;
      if (find_par(i) != find_par(leftmn)) {
        make_union(i, leftmn);
        edges.push_back({p[i], p[leftmn]});
      }
    }
    if (p[i] < p[rightmx]) {
      if (minchecked == -1)
        minchecked = i;
      if (p[minchecked] > p[i])
        minchecked = i;
      if (find_par(i) != find_par(rightmx)) {
        edges.push_back({p[i], p[rightmx]});
        make_union(i, rightmx);
      }
    }
    if (minchecked != -1 && p[i] > p[minchecked]) {
      if (find_par(i) != find_par(minchecked)) {
        make_union(i, minchecked);
        edges.push_back({p[i], p[minchecked]});
      }
    }
  }
  int maxchecked = -1;
  for (int i = mn - 1; i > mx; i--) {
    if (p[i] > p[leftmn]) {
      if (maxchecked == -1)
        maxchecked = i;
      if (p[maxchecked] < p[i])
        maxchecked = i;
      if (find_par(i) != find_par(leftmn)) {
        make_union(i, leftmn);
        edges.push_back({p[i], p[leftmn]});
      }
    }
    if (p[i] < p[rightmx]) {
      if (maxchecked == -1)
        maxchecked = i;
      if (p[maxchecked] < p[i])
        maxchecked = i;
      if (find_par(i) != find_par(rightmx)) {
        make_union(i, rightmx);
        edges.push_back({p[i], p[rightmx]});
      }
    }
    if (maxchecked != -1 && p[i] < p[maxchecked]) {
      if (find_par(i) != find_par(maxchecked)) {
        make_union(i, maxchecked);
        edges.push_back({p[i], p[maxchecked]});
      }
    }
  }
  // for (auto c : dsu) {
  //   cout << c << " ";
  // }
  // cout << "\n";
  int u = find_par(0);
  for (int i = 1; i < n; i++) {
    if (find_par(i) != u) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
  for (auto [u, v] : edges) {
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
