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
  vector<ll> ans(n);
  ans[0] = min(b[0] - a[0], a[0]);
  for (int i = 1; i < n; i++)
  {
    ans[i] = b[0] - a[i];
  }
  vector<ll> ans2(n);
  ans2[0] = ans[0];
  for (int i = 1; i < n; i++)
  {
    if (ans2[i - 1] <= min(ans[i], a[i]))
    {
      ans2[i] = min(ans[i], a[i]);
    }
    else if (ans2[i - 1] <= ans[i])
    {
      ans2[i] = ans[i];
    }
    else if (ans2[i - 1] <= a[i])
    {
      ans2[i] = a[i];
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