#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

ll MOD = 1e9 + 7;
ll pw_mod(ll a, ll b)
{
  ll res = 1;
  while (b)
  {
    if (b & 1)
    {
      res = (res * a) % MOD;
    }
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res % MOD;
}

void solve()
{
  int t;
  cin >> t;
  vector<int> p(t);
  vector<int> q(t);
  ll N = 5;
  for (auto &c : p)
    cin >> c;
  for (auto &c : q)
    cin >> c;
  for (int i = 0; i < t; i++)
  {
    cout << pw_mod(2, q[i]) % MOD << "\n";
  }
}

int main(void)
{
  optimize();
  int T;
  // cin >> T;
  T = 1;
  while (T--)
    solve();
}