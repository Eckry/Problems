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
  vector<vector<ll>> a(n, vector<ll>(2));
  for (int i = 0; i < n; i++)
  {
    cin >> a[i][0];
    cin >> a[i][1];
  }

  vector<int> idx(n);
  iota(idx.begin(), idx.end(), 0);

  sort(idx.begin(), idx.end(), [&](int u, int b)
       { return (a[u][0] + a[u][1]) < (a[b][0] + a[b][1]); });

  for (int i = 0; i < n; i++)
  {
    cout << a[idx[i]][0] << " " << a[idx[i]][1] << " ";
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