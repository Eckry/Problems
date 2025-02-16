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
  ll x, y;
  cin >> x >> y;

  vector<ll> ans;
  ans.push_back(x);
  for (int i = x - 1; i >= y; i--)
    ans.push_back(i);

  for (int i = y + 1; i <= x - 1; i++)
    ans.push_back(i);
  cout << ans.size() << "\n";
  for (auto c : ans)
    cout << c << " ";
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