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
  {
    if (mp[1] > 0)
    {
      mp[n]--;
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    if (mp[n] > 0)
    {
      mp[n]--;
      return 1;
    }
    long long x = n / 2;
    long long y = (n + 1) / 2;

    if (x == y)
    {
      if (mp[x] > 1)
      {
        mp[x] -= 2;
        return 1;
      }
      else
      {
        return (check(x) && check(y));
      }
    }
    if (mp[x] > 0 && mp[y] > 0)
    {
      mp[x]--;
      mp[y]--;
      return 1;
    }
    else
    {
      return (check(x) && check(y));
    }
  }
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<long long> a(n);
  vector<long long> b(m);
  for (auto &c : a)
    cin >> c;
  for (auto &c : b)
    cin >> c;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  mp.clear();
  for (int i = 0; i < n; i++)
  {
    mp[a[i]]++;
  }

  // for (auto c : mp)
  // {
  //   cout << c.first << " " << c.second << " ";
  //   cout << "\n";
  // }
  // cout << "\n";

  long long ans = 0;
  for (int i = 0; i < m; i++)
  {
    if (check(b[i]))
    {
      ans++;
    }
    else
    {
      cout << "NO" << "\n";
      return;
    }
  }

  for (auto c : mp)
  {
    if (c.second > 0)
    {
      cout << "NO" << "\n";
      return;
    }
  }
  // for (auto c : mp)
  // {
  //   cout << c.first << " " << c.second << " ";
  //   cout << "\n";
  // }
  cout << "YES" << "\n";
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