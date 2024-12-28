#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n;
  cin >> n;
  map<int, int> forced;
  vector<pair<int, int>> data;
  int mx = 0;
  for (int i = 0; i < n; i++)
  {
    int l, r;
    cin >> l >> r;
    data.push_back({l, r});
    mx = max(r, mx);
    if (l == r)
    {
      forced[l]++;
    }
  }

  vector<int> free(mx + 2);
  int count = 0;
  for (int i = 1; i <= mx + 1; i++)
  {
    if (forced[i])
      count++;
    free[i] = i - count;
  }

  for (int i = 0; i < n; i++)
  {
    int l = data[i].first;
    int r = data[i].second; // 1 1 2 2 3 4 5 6
    if (r == l && forced[l] == 1)
    {
      cout << 1;
    }
    else if (free[r] - free[l - 1] > 0)
    {
      cout << 1;
    }
    else
      cout << 0;
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