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
  vector<long long int> a(n);
  for (auto &c : a)
    cin >> c;

  long long int distinct = 0;
  map<long long int, long long int> m;

  for (int i = 0; i < n; i++)
  {
    if (!m[a[i]])
    {
      distinct++;
    }
    m[a[i]]++;
  }

  vector<long long int> x;
  for (auto c : m)
  {
    x.push_back(c.second); // 2 2 3 4
  }

  sort(x.begin(), x.end());
  long long int ans = distinct;
  for (int i = 0; i < x.size(); i++)
  {
    if (ans == 1)
      break;

    if (k < x[i])
      break;

    if (k >= x[i])
    {
      k -= x[i];
      ans--;
    }

    if (k <= 0)
      break;
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