#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n;
  cin >> n;
  int increment = 1;
  int flg = 0;
  bool res = 1;
  for (int i = 0; i < n; i += increment)
  {
    if (flg)
    {
      flg = 0;
      res = !res;
      increment++;
      continue;
    }
    res = !res;
    flg = 1;
  }
  if (res)
    cout << "John" << endl;
  else
    cout << "Jane" << endl;
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