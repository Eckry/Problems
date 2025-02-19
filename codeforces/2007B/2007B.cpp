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
  for (auto &c : a)
    cin >> c;
  ll mx = 0;
  for (int i = 0; i < n; i++)
  {
    mx = max(mx, a[i]);
  }
  while (m--)
  {
    char op;
    cin >> op;
    ll l, r;
    cin >> l >> r;
    if (op == '-' && l <= mx && r >= mx)
    {
      mx--;
    }
    if (op == '+' && l <= mx && r >= mx)
    {
      mx++;
    }
    cout << mx << " ";
  }
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