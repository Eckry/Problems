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
  vector<long long> u(n);
  for (auto &c : u)
    cin >> c;

  map<long long, vector<long long>> mp;

  for (int i = 0; i < n; i++)
  {
    mp[u[i]].push_back(i);
  }

  while (k--)
  {
    long long a, b;
    cin >> a >> b;

    if (mp.count(a) && mp.count(b))
    {
      if (mp[a][0] < mp[b][mp[b].size() - 1])
        cout << "YES" << "\n";
      else
        cout << "NO" << "\n";
    }
    else
    {
      cout << "NO" << "\n";
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