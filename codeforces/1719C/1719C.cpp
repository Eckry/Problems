#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  for (auto &c : a)
    cin >> c;

  vector<vector<int>> wins(n, vector<int>());
  vector<int> finalState;

  int last = 0;
  for (int i = 1; i < n; i++)
  {
    if (a[last] > a[i])
    {
      wins[last].push_back(i);
      finalState.push_back(a[i]);
    }
    else
    {
      wins[i].push_back(i);
      finalState.push_back(a[last]);
      last = i;
    }
  }

  while (q--)
  {
    int i;
    long long k;
    cin >> i >> k;
    i--;
    if (i == last)
    {
      if (k > n - 1)
      {
        cout << wins[i].size() + k - n + 1 << "\n";
      }
      else
      {
        int ans = upper_bound(wins[i].begin(), wins[i].end(), k) - wins[i].begin();
        cout << ans << "\n";
      }
    }
    else
    {
      int ans = upper_bound(wins[i].begin(), wins[i].end(), k) - wins[i].begin();
      cout << ans << "\n";
    }
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