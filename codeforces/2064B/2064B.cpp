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
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;
  if (a.size() == 1)
  {
    cout << 1 << " " << 1 << "\n";
    return;
  }

  map<int, int> mp;
  for (int i = 0; i < n; i++)
  {
    if (!mp.count(a[i]))
    {
      mp[a[i]] = i;
    }
    else
    {
      mp[a[i]] = -1;
    }
  }

  vector<int> ans;
  for (auto c : mp)
  {
    if (c.second != -1)
    {
      ans.push_back(c.second);
    }
  }
  if (ans.size() == 0)
  {
    cout << 0 << "\n";
    return;
  }

  if (ans.size() == 1)
  {
    cout << ans[0] + 1 << " " << ans[0] + 1 << "\n";
    return;
  }
  sort(ans.begin(), ans.end());
  int mn = -1;
  int mx = -1;
  int cnt = 0;
  int best = -1;
  int mnans = -1;
  int mxans = -1;
  for (int i = 0; i < (int)ans.size() - 1; i++)
  {
    if (ans[i] + 1 == ans[i + 1])
    {
      cnt++;
      if (mn == -1)
        mn = ans[i];
      mx = ans[i + 1];
    }
    else if (ans[i] + 1 != ans[i + 1])
    {
      mn = -1;
      cnt = 0;
    }
    if (best < cnt)
    {
      best = cnt;
      mnans = mn;
      mxans = mx;
    }
  }
  if (mnans == -1 && mxans == -1)
    cout << ans[0] + 1 << " " << ans[0] + 1 << "\n";
  else
    cout << mnans + 1 << " " << mxans + 1 << "\n";
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