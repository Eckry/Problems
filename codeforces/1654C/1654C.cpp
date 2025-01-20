#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

map<long long, long long> mp;

bool check(long long n)
{
  if (n == 1)
    if (mp[1] > 0)
    {
      mp[1]--;
      return 1;
    }
    else
      return 0;
  else
  {
    if (mp[n] > 0)
    {
      mp[n]--;
      return 1;
    }

    long long x = n / 2;
    long long y = (n + 1) / 2;

    return (check(x) && check(y));
  }
}

void solve()
{
  int n;
  cin >> n;
  vector<long long> a(n);
  for (auto &c : a)
    cin >> c;

  long long sm = 0;
  mp.clear();
  for (int i = 0; i < n; i++)
  {
    mp[a[i]]++;
    sm += a[i];
  }

  if (check(sm))
  {
    cout << "YES" << "\n";
  }
  else
    cout << "NO" << "\n";
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