#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<vector<int>> adj;
string s;
int n;

vector<int> findN(int v, int p) {
  vector<int> path;
  if (v == n - 1) {
    return {v};
  }
  for (auto u : adj[v]) {
    if (u == p)
      continue;
    if (!path.size()) {
      path = findN(u, v);
    }
    if (path.size()) {
      path.push_back(v);
      break;
    }
  }
  return path;
}

int one;
int ncnt;
int prohib;
int nextprohi;

int dfs(int v, int p) {
  int ok = ((s[v] - '0') == 1);

  for (auto u : adj[v]) {
    if (u == p || u == prohib)
      continue;
    if (dfs(u, v)) {
      ok = 1;
    }
  }
  if (ok) {
    one++;
    // cout << v << "\n";
  }
  return ok;
}

int dfs2(int v, int p) {
  int ok = ((s[v] - '0') == 1);

  for (auto u : adj[v]) {
    if (u == p || nextprohi == u)
      continue;
    if (dfs2(u, v)) {
      ok = 1;
    }
  }
  if (ok)
    ncnt++;
  return ok;
}

void solve() {
  cin >> n;
  adj = vector<vector<int>>(n, vector<int>());
  for (int i = 0; i < n - 1; i++) {
    int x;
    cin >> x;
    x--;
    adj[x].push_back(i + 1);
    adj[i + 1].push_back(x);
  }
  cin >> s;
  vector<int> path = findN(0, -1);
  int k = path.size();
  int ans = 10000000;
  for (int i = 0; i < k - 1; i++) {
    one = 0;
    ncnt = 0;
    prohib = path[i];
    nextprohi = path[i + 1];
    // cout << prohib << " " << nextprohi << "\n";
    dfs(0, -1);
    dfs2(n - 1, -1);
    if (one)
      one--;
    if (ncnt)
      ncnt--;
    ans = min(ans, (one + ncnt) * 2);
    // cout << one << " " << ncnt << "\n";
  }
  cout << ans;
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
