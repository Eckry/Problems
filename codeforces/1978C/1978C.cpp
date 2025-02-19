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
  ll n, k;
  cin >> n >> k;
  vector<ll> test;
  vector<ll> num(n + 1, 0);
  if (k > (n * n) / 2 || k & 1)
  {
    cout << "NO" << "\n";
    return;
  }
  vector<ll> ans(n);
  iota(ans.begin(), ans.end(), 0);
  for (int i = 0; k > 0; i++)
  {
    if (k >= 2 * (n - 1 - 2 * i))
    {
      swap(ans[i], ans[n - 1 - i]);
      k -= 2 * (n - 1 - 2 * i);
    }
    else
    {
      swap(ans[i], ans[i + k]);
      k = 0;
    }
  }

  cout << "YES" << "\n";
  for (auto c : ans)
    cout << c + 1 << " ";
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