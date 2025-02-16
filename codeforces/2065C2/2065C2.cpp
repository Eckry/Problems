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
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  vector<ll> b(m);
  for (auto &it : a)
    cin >> it;
  for (auto &it : b)
    cin >> it;
  sort(b.begin(), b.end());
  ll mn = b[0];
  vector<ll> op(n);
  op[0] = min(mn - a[0], a[0]);
  for (int i = 1; i < n; i++)
  {
    ll x = lower_bound(b.begin(), b.end(), a[i] + op[i - 1]) - b.begin();
    if (x == m)
      x--;
    if (op[i - 1] <= min(b[x] - a[i], a[i]))
    {
      op[i] = min(b[x] - a[i], a[i]);
    }
    else if (op[i - 1] <= b[x] - a[i])
    {
      op[i] = b[x] - a[i];
    }
    else if (op[i - 1] <= a[i])
    {
      op[i] = a[i];
    }
    else
    {
      cout << "NO" << "\n";
      return;
    }
  }
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