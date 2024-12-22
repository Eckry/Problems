#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  long long int w, b;
  cin >> w >> b;

  long long int mx = max(w, b);

  long long int r = mx;
  long long int l = 0;

  for (int f = (mx + 1) / 2; f >= 1; f /= 2)
  {
    while (l + f <= r && (f + l) * ((f + l) + 1) / 2 <= w + b)
      l += f;
  }
  cout << l << "\n";
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