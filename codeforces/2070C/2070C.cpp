#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

vector<ll> a;
ll n, k;
string s;
bool check(ll d)
{
  char last = 'R';
  ll cnt = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] > d)
    {
      if (s[i] == 'B' && last == 'R')
      {
        cnt++;
      }
      last = s[i];
    }
  }
  return cnt <= k;
}

void solve()
{
  cin >> n >> k;
  cin >> s;
  a = vector<ll>(n);
  for (auto &c : a)
    cin >> c;

  ll l = 0;
  ll r = 1e9;
  ll ans = -1;
  while (l <= r)
  {
    ll mid = (l + r) / 2;
    if (check(mid))
    {
      ans = mid;
      r = mid - 1;
    }
    else
    {
      l = mid + 1;
    }
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