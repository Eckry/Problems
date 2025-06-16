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
  vector<vector<ll>> coord(n, vector<ll>(2));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      cin >> coord[i][j];
    }
  }

  if (n == 1)
  {
    cout << 1 << "\n";
    return;
  }

  vector<int> X(n);
  vector<int> Y(n);
  iota(X.begin(), X.end(), 0);
  sort(X.begin(), X.end(), [&](int a, int b)
       { return coord[a][0] > coord[b][0]; });
  iota(Y.begin(), Y.end(), 0);
  sort(Y.begin(), Y.end(), [&](int a, int b)
       { return coord[a][1] > coord[b][1]; });
  ll ans = LONG_LONG_MAX;
  for (int i = 0; i < n; i++)
  {
    ll lengthX = coord[X[0]][0] - coord[X[n - 1]][0] + 1;
    ll lengthY = coord[Y[0]][1] - coord[Y[n - 1]][1] + 1;
    if (X[0] == i)
      lengthX = coord[X[1]][0] - coord[X[n - 1]][0] + 1;
    if (X[n - 1] == i)
      lengthX = coord[X[0]][0] - coord[X[n - 2]][0] + 1;
    if (Y[0] == i)
      lengthY = coord[Y[1]][1] - coord[Y[n - 1]][1] + 1;
    if (Y[n - 1] == i)
      lengthY = coord[Y[0]][1] - coord[Y[n - 2]][1] + 1;
    ll area = lengthX * lengthY;
    if (area == n - 1)
    {
      ans = min(area + min(lengthX, lengthY), ans);
    }
    else
      ans = min(area, ans);
    // cout << area << " " << lengthY << "\n";
  }
  cout << ans << "\n";
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