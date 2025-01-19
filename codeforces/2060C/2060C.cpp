#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> x(n);
  for (auto &c : x)
    cin >> c;

  sort(x.begin(), x.end());
  map<int, int> mp;
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    if (mp[x[i]])
    {
      ans++;
      mp[x[i]]--;
    }
    else
    {
      int target = k - x[i];
      mp[target]++;
    }
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