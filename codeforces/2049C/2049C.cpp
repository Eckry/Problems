#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

vector<vector<long long int>> a;
vector<long long int> b;

void dfs(long long int v)
{
  if (b[v] != -1)
    return;

  set<long long int> used;

  for (auto c : a[v])
  {
    if (b[c] == -1)
      continue;
    used.insert(b[c]);
  }

  int MEX = 0;
  while (used.count(MEX))
    MEX++;
  b[v] = MEX;
  for (auto c : a[v])
    dfs(c);
}

void solve()
{
  int n, x, y;
  cin >> n >> x >> y;
  b.assign(n + 1, -1);
  a.assign(n + 1, vector<long long int>());

  for (int i = 1; i <= n; i++)
  {
    if (i != n)
      a[i].push_back(i + 1);
    else
      a[i].push_back(1);
    if (i != 1)
      a[i].push_back(i - 1);
    else
      a[i].push_back(n);
  }

  a[x].push_back(y);
  a[y].push_back(x);

  dfs(x);

  for(int i = 1; i <= n; i++){
    cout << b[i] << " ";
  }
  cout << "\n";
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