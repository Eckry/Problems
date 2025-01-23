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

  ll sm = 0;
  for (int i = 0; i < n; i++)
    sm += a[i];

  // cout << sm << "\n";
  map<int, int> mp;

  ll sm2 = 0;
  int lastmx = 0;
  for (int i = 0; i < n; i++)
  {
    mp[a[i]]++;
    if (mp[a[i]] == 2 && lastmx < a[i])
    {
      lastmx = a[i];
    }
    a[i] = lastmx;
    sm2 += a[i];
  }
  // for (auto c : a)
  //   cout << c << " ";
  // cout << "\n";
  sm += sm2;
  // cout << sm << "\n";
  sm2 = 0;
  mp.clear();
  lastmx = 0;
  for (int i = 0; i < n; i++)
  {
    mp[a[i]]++;
    if (mp[a[i]] == 2 && lastmx < a[i])
    {
      lastmx = a[i];
    }
    a[i] = lastmx;
    sm2 += a[i];
  }
  // for (auto c : a)
  //   cout << c << " ";
  // cout << "\n";

  sm += sm2;
  // cout << sm << "\n";

  for (int i = n - 1; i >= 0; i--)
  {
    sm2 -= a[i];
    sm += sm2;
  }
  cout << sm << "\n";
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