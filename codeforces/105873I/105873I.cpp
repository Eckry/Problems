#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<vector<int>> adj;
vector<int> K;
vector<int> tin;
vector<int> tout;
map<int, vector<int>> mp;
int timer;

void dfs(int v, int p) {
  mp[K[v]].push_back(timer);
  tin[v] = timer++;
  for (auto u : adj[v]) {
    if (p == u)
      continue;
    dfs(u, v);
  }
  tout[v] = timer;
}

void solve() {
  int n, q;
  cin >> n >> q;
  K = vector<int>(n);
  adj = vector<vector<int>>(n, vector<int>());
  tin = vector<int>(n);
  tout = vector<int>(n);
  mp = map<int, vector<int>>();
  timer = 0;
  for (auto &c : K)
    cin >> c;

  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    adj[x].push_back(y);
  }
  dfs(0, -1);
  for (auto &p : mp) {
    auto &vec = p.second;
    sort(vec.begin(), vec.end());
  }
  while (q--) {
    int x, k;
    cin >> x >> k;
    x--;
    if (mp.find(k) != mp.end()) {
      int start = tin[x];
      int end = tout[x];
      int l = lower_bound(mp[k].begin(), mp[k].end(), start) - mp[k].begin();
      int r = lower_bound(mp[k].begin(), mp[k].end(), end) - mp[k].begin();
      cout << r - l << "\n";
    } else {
      cout << 0 << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  T = 1;
  while (T--)
    solve();
}
