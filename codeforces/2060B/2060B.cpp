#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> cows(n, vector<int>(m));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> cows[i][j];
    }
  }

  for (int i = 0; i < n; i++)
  {
    sort(cows[i].begin(), cows[i].end());
  }

  vector<int> ids(n);
  iota(ids.begin(), ids.end(), 0);
  sort(ids.begin(), ids.end(), [&](int a, int b)
       { return cows[a][0] < cows[b][0]; });
  sort(cows.begin(), cows.end(), [&](vector<int> a, vector<int> b)
       { return a[0] > b[0]; });

  int last = -1;
  for (int i = 0; i < m; i++)
  {
    for (int j = n - 1; j >= 0; j--)
    {
      if (last > cows[j][i])
      {
        cout << -1 << "\n";
        return;
      }
      last = cows[j][i];
    }
  }

  for (auto c : ids)
  {
    cout << c + 1 << " ";
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