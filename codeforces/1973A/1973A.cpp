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
  int p1, p2, p3;
  cin >> p1 >> p2 >> p3;
  ll ans = 0;

  while (p1 + p2 > p3)
  {
    p1--;
    p2--;
    ans++;
  }

  while (p1)
  {
    ans++;
    p1--;
    p3--;
  }

  while (p3 && p2)
  {
    ans++;
    p2--;
    p3--;
  }

  if (max(p2, p3) & 1)
  {
    cout << -1 << "\n";
    return;
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