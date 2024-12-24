#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  long long int n, d;
  cin >> n >> d;

  cout << 1 << " ";

  if (d == 3 || d == 6 || d == 9)
    cout << 3 << " ";
  else
  {
    if (n >= 3)
      cout << 3 << " ";
  }

  if (d == 5)
    cout << 5 << " ";
  if (d == 7)
    cout << 7 << " ";
  else if (n >= 3)
  {
    cout << 7 << " ";
  }

  if (d == 9)
    cout << 9 << " ";
  else
  {
    if (n >= 6)
      cout << 9 << " ";
    else if ((d == 3 || d== 6) && n >= 3)
      cout << 9 << " ";
  }
  cout << "\n";

  // for (long long int i = 1; i < 10; i++)
  // {
  //   cout << (111111111111 * i) % 9 << " ";
  // }
  // cout << "\n";
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