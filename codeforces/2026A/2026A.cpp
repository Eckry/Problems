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
  int x, y, k;
  cin >> x >> y >> k;
  int sq = min(x, y);
  cout << 0 << " " << sq << " " << sq << " " << 0 << "\n";
  cout << 0 << " " << 0 << " " << sq << " " << sq << "\n";
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