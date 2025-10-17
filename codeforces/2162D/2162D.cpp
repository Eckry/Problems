#include <bits/stdc++.h>

using namespace std;

#define ll long long
int n;

const ll INF = 1e9 + 7;
int diff = 0;
struct SegTree {
  vector<int> sg;
  vector<int> sgmod;
  int N;

  SegTree(int n) {
    N = 1;
    while (N < n)
      N <<= 1;
    sg.assign(N << 1, -1);
    sgmod.assign(N << 1, -1);
    sg[1] = (n * (n + 1)) / 2;
  }
  int ask(int v, int tl, int tr) {
    ll real;
    ll modif;
    if (sg[v] != -1) {
      real = sg[v];
    } else {
      cout << 1 << " " << tl + 1 << " " << tr + 1 << endl;
      cin >> real;
    }
    if (sgmod[v] != -1) {
      modif = sgmod[v];
    } else {
      cout << 2 << " " << tl + 1 << " " << tr + 1 << endl;
      cin >> modif;
    }
    if (tr == n - 1 && tl == 0) {
      diff = modif - real;
    }
    // cout << real << " " << modif << "\n";
    if (v != 1) {
      sg[v] = real;
      sg[v ^ 1] = sg[v >> 1] - real;
      sgmod[v] = modif;
      sgmod[v ^ 1] = sgmod[v >> 1] - modif;
    }
    int tm = (tl + tr) >> 1;
    if (real != modif) {
      if (tl == tr)
        return tr;
      int left = ask(v << 1, tl, tm);
      if (left != INF)
        return left;
      return ask(v << 1 | 1, tm + 1, tr);
    } else {
      return INF;
    }
  }
};

void solve() {
  cin >> n;
  diff = 0;
  SegTree sg(n);
  int l = sg.ask(1, 0, n - 1);
  cout << "! " << l + 1 << " " << l + diff << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
