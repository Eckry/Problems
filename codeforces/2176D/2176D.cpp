#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct Edge {
  int v, u;
  ll s;
  Edge() {}
  Edge(int v, int u, ll s) : v(v), u(u), s(s) {}
  bool operator<(const Edge &other) const { return s < other.s; }
};

vector<vector<ll>> adj;
vector<map<ll, ll>> dp;

const ll MOD = 998244353;

void solve() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  adj = vector<vector<ll>>(n, vector<ll>());
  dp = vector<map<ll, ll>>(n, map<ll, ll>());
  vector<Edge> edg;
  for (auto &c : a)
    cin >> c;
  for (int i = 0; i < m; i++) {
    ll v, u;
    cin >> v >> u;
    v--;
    u--;
    adj[v].push_back(u);
    edg.push_back(Edge(v, u, a[v] + a[u]));
  }
  sort(edg.begin(), edg.end());
  reverse(edg.begin(), edg.end());
  ll ans = 0;
  for (auto e : edg) {
    int u = e.u;
    int v = e.v;
    ll s = e.s;
    ll lol = (dp[u][s] + 1) % MOD;
    dp[v][a[u]] = (dp[v][a[u]] + lol) % MOD;
    ans = (ans + lol) % MOD;
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
