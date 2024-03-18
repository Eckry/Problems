#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int N, K, L;
  cin >> N >> K >> L;
  int res = N * K / L + (N * K % L != 0);
  cout << res << endl;
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