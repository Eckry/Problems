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
  vector<int> d(n);
  for (auto &c : d)
    cin >> c;

  vector<vector<int>> obs(n, vector<int>(2));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      cin >> obs[i][j];
    }
  }

  vector<int> range = {0, 0};
  int last = 0;
  for (int i = 0; i < n; i++)
  {
    if (d[i] != -1)
    {
      range[0] += d[i];
      range[1] += d[i];
    }
    else
    {
      range[1]++;
    }

    if (obs[i][0] > range[1] || obs[i][1] < range[0])
    {
      cout << -1 << "\n";
      return;
    }
    if (range[1] > obs[i][1])
    {
      int diff = range[1] - obs[i][1];
      range[1] = obs[i][1];
      int cnt = 0;
      for (int j = last; j <= i; j++)
      {
        if (d[j] == -1)
        {
          last = j;
          cnt++;
          d[j] = 0;
        }
        if (cnt == diff)
          break;
      }
    }
    if (range[0] < obs[i][0])
    {
      int diff = obs[i][0] - range[0];
      range[0] = obs[i][0];
      int cnt = 0;
      for (int j = last; j <= i; j++)
      {
        if (d[j] == -1)
        {
          last = j;
          cnt++;
          d[j] = 1;
        }
        if (cnt == diff)
          break;
      }
    }
  }
  for (auto c : d)
  {
    if (c == -1)
      cout << 0 << " ";
    else
      cout << c << " ";
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