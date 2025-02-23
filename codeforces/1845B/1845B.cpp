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
  ll bx, by;
  cin >> bx >> by;
  ll cx, cy;
  cin >> cx >> cy;

  ll hb = bx - x;
  ll hc = cx - x;
  ll ans = 1;
  if (hb > 0 && hc > 0)
    ans += min(abs(hb), abs(hc));
  else if (hb < 0 && hc < 0)
    ans += min(abs(hb), abs(hc));

  ll vb = by - y;
  ll vc = cy - y;
  if (vb > 0 && vc > 0)
    ans += min(abs(vb), abs(vc));
  else if (vb < 0 && vc < 0)
    ans += min(abs(vb), abs(vc));
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