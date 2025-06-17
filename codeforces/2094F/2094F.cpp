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
  int n, m, k;
  cin >> n >> m >> k;
  int cnt = 0;
  if (n % k != 0)
  {
    vector<vector<int>> xd(n, vector<int>(m));
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        xd[j][i] = (cnt % k + 1);
        cnt++;
      }
    }

    for(auto c : xd) {
      for(auto d : c) {
        cout << d << " ";
      }
      cout << "\n";
    }
    return;
  }

  if (m % k != 0)
  {
    vector<vector<int>> xd(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        xd[i][j] = (cnt % k + 1);
        cnt++;
      }
    }

    for(auto c : xd) {
      for(auto d : c) {
        cout << d << " ";
      }
      cout << "\n";
    }
    return;
  }

  vector<int> ans(k);
  iota(ans.begin(), ans.end(), 1);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << ans[(j + i) % k] << " ";
    }
    cout << "\n";
  }
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