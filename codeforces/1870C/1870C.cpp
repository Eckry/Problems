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
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (auto &c : a)
    cin >> c;
  map<int, vector<int>> mp;
  for (int i = 0; i < n; i++)
  {
    mp[a[i]].push_back(i);
  }
  sort(a.begin(), a.end(), greater<>());
  int mx = -1;
  int mn = n + 2;

  vector<int> ans(k + 1, -1);

  for (int i = 0; i < n; i++)
  {
    if (ans[a[i]] == -1)
    {
      mx = max(mp[a[i]][mp[a[i]].size() - 1], mx);
      mn = min(mp[a[i]][0], mn);
      ans[a[i]] = mx - mn + 1;
    }
  }
  for (int i = 0; i < k; i++)
  {
    if (ans[i + 1] == -1)
    {
      cout << 0 << ' ';
    }
    else
      cout << ans[i + 1] * 2 << " ";
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