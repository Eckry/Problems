#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{

  int l, r;
  cin >> l >> r;
  int L, R;
  cin >> L >> R;
  long long int count = 0;

  for (int i = l; i <= r; i++)
  {
    if (L <= i && i <= R)
      count++;
  }

  if (R == r)
    count--;
  if (l == L)
    count--;
  long long int ans = count + 1;

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