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

  map<long long, int> mp;
  int cnt = 0;
  int cnt2 = 0;

  for (int i = 0; i < n; i++)
  {
    if (mp[a[i]] == 1)
    {
      cnt--;
      cnt2++;
    }
    if (!mp[a[i]])
      cnt++;

    mp[a[i]]++;
  }

  cout << cnt2 + (cnt + 1) / 2 << "\n";
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