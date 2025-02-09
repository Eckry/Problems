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
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;

  vector<bool> vis(n, 0);
  int cur_or = 0;
  for (int i = 0; i < min(31LL, n); i++)
  {
    int mx = 0;
    int idx = -1;
    for (int j = 0; j < n; j++)
    {
      if (vis[j])
        continue;
      if ((cur_or | a[j]) > mx)
      {
        mx = (cur_or | a[j]);
        idx = j;
      }
    }
    vis[idx] = 1;
    cur_or |= a[idx];
    cout << a[idx] << " ";
  }
  for (int i = 0; i < n; i++)
    if (!vis[i])
      cout << a[i] << " ";
  cout << "\n";
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