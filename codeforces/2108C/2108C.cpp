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

  ll ans = 0;

  if (n == 1)
  {
    cout << "1" << "\n";
    return;
  }

  if (a[0] > a[1])
    ans++;
  if (a[n - 1] > a[n - 2])
    ans++;
  int flg = 0;
  if (a[0] == a[1])
    flg = 1;
  for (int i = 1; i < n - 1; i++)
  {
    if (a[i - 1] < a[i] && a[i] > a[i + 1])
    {
      ans++;
    }
    if (a[i - 1] < a[i] && a[i] == a[i + 1])
      flg = 1;
    if (a[i] > a[i + 1] && flg)
    {
      ans++;
      flg = 0;
    }
    if (a[i] < a[i + 1])
      flg = 0;
  }
  ans += (flg == 1);

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