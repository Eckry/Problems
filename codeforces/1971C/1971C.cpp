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
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int cnt = 0;
  for (int i = min(a, b); i <= max(a, b); i++)
  {
    if (i == c || i == d)
      cnt++;
  }

  if (cnt == 2 || cnt == 0)
  {
    cout << "NO" << "\n";
  } else {
    cout << "YES" << "\n";
  }
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