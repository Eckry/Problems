#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1, vector<int>());
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  string s = string(n, '0');

  for (int i = 0; i < n - 1; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }


  for (int i = 1; i <= n; i++)
  {
    map<int, int> cnt;
    for(auto v : adj[i]){
      cnt[a[v]]++;
    }
    cnt[a[i]]++;
    for(auto c : cnt) {
      if(c.second >= 2) s[c.first - 1] = '1';
    }
  }

  cout << s << "\n";
}

int main(void)
{
  optimize();
  int T;
  cin >> T;
  // T = 1;
  while (T--)
    solve();
}