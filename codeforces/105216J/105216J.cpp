#include <bits/stdc++.h>

using namespace std;

#define ll long long

int id;
vector<int> comp;
vector<vector<int>> adj;
vector<vector<int>> comp_vec;

void dfs(int v, int p) {
  if (comp[v] != -1)
    return;
  comp[v] = id;
  comp_vec[id].push_back(v);
  for (auto u : adj[v]) {
    if (p == u)
      continue;
    dfs(u, v);
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  comp = vector<int>(n, -1);
  adj = vector<vector<int>>(n, vector<int>());
  comp_vec = vector<vector<int>>(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int v, u;
    cin >> v >> u;
    v--;
    u--;
    adj[v].push_back(u);
    adj[u].push_back(v);
  }
  if (n == 1) {
    cout << "NO" << "\n";
    return;
  } else if (n == 2) {
    cout << "YES\n0\n";
    return;
  }
  cout << "YES" << "\n";
  int cnt = 0;
  vector<pair<int, int>> intro;
  for (int v = 0; v < n / 2; v++) {
    set<int> st;
    for (auto u : adj[v]) {
      st.insert(u);
    }
    for (int u = 0; u < n / 2; u++) {
      if (u == v)
        continue;
      if (st.find(u) == st.end()) {
        st.insert(u);
        adj[u].push_back(v);
        adj[v].push_back(u);
        intro.push_back({u, v});
        cnt++;
      }
    }
  }
  for (int v = n / 2; v < n; v++) {
    set<int> st;
    for (auto u : adj[v]) {
      st.insert(u);
    }
    for (int u = n / 2; u < n; u++) {
      if (u == v)
        continue;
      if (st.find(u) == st.end()) {
        st.insert(u);
        adj[u].push_back(v);
        adj[v].push_back(u);
        intro.push_back({u, v});
        cnt++;
      }
    }
  }

  cout << cnt << "\n";
  for (auto par : intro) {
    cout << par.first + 1 << " " << par.second + 1 << "\n";
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
