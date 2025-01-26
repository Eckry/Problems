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
  ll n;
  cin >> n;
  vector<ll> a(n - 1);
  for (auto &c : a)
    cin >> c;
  map<ll, ll> mp;

  ll f = n * (n + 1) / 2;
  if (a[n - 2] != f)
  {
    a.push_back(f);
    vector<int> per;
    per.push_back(a[0]);
    for (int i = 0; i < n - 1; i++)
    {
      ll diff = a[i + 1] - a[i];
      if (mp.count(diff))
      {
        cout << "NO" << "\n";
        return;
      }
      mp[diff]++;
      per.push_back(diff);
    }

    for (int i = 0; i < n; i++)
    {
      if (per[i] <= 0 || per[i] > n)
      {
        cout << "NO" << "\n";
        return;
      }
    }
    set<ll> s(per.begin(), per.end());
    if (s.size() == n)
      cout << "YES" << "\n";
    else
      cout << "NO" << "\n";
    return;
  }
  mp[a[0]]++;
  int cnt = 0;
  for (int i = 1; i < n - 1; i++)
  {
    ll diff = a[i] - a[i - 1];
    mp[diff]++;
    if (mp[diff] == 2)
      cnt++;
    if (cnt == 2 || mp[diff] == 3)
    {
      cout << "NO" << "\n";
      return;
    }
  }

  vector<ll> left;
  for (int i = 1; i <= n; i++)
  {
    if (mp[i] == 0)
    {
      left.push_back(i);
    }
  }
  if (left.size() != 2)
  {
    cout << "NO" << "\n";
  }
  else
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