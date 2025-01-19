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
  vector<long long> a(n);
  for (auto &c : a)
    cin >> c;

  map<long long, long long> mp;
  long long ans = 0;

  for (int i = 0; i < n; i++)
  {
    if (a[i] == 1 && mp.count(2))
    {
      ans += mp[2];
    }
    else if (a[i] == 2 && mp.count(1))
    {
      ans += mp[1];
    }
    if (mp.count(a[i]))
    {
      ans += mp[a[i]];
    }
    mp[a[i]]++;
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