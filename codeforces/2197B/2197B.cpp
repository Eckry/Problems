#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int INF = 100000000;

void solve() {

  int n;
  cin >> n;
  vector<int> p(n);
  vector<int> a(n);
  for (auto &c : p)
    cin >> c;
  for (auto &c : a)
    cin >> c;

  vector<pair<int, int>> seg(n + 1, pair<int, int>({INF, -1}));
  for (int i = 0; i < n; i++) {
    int v = p[i];
    seg[v].first = min(seg[v].first, i);
    seg[v].second = max(seg[v].second, i);
  }

  int point = -1;
  for (int i = 0; i < n; i++) {
    int v = a[i];
    if (seg[v].first == INF)
      continue;
    if (point > seg[v].first) {
      cout << "NO\n";
      return;
    }
    point = seg[v].second;
  }
  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
