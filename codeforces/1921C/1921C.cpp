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
  ll n, f, a, b;
  cin >> n >> f >> a >> b;
  vector<ll> m(n + 1);
  m[0] = 0;
  for (int i = 1; i <= n; i++)
    cin >> m[i];

  for (int i = 0; i <= n - 1; i++)
  {
    ll qnt = min((m[i + 1] - m[i]) * a, b);
    f -= qnt;
  }

  if (f > 0)
    cout << "YES" << "\n";
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