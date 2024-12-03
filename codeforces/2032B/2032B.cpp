#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n, k;
  cin >> n >> k;

  if (n == 1)
    cout << "1\n1\n";
  else
  {
    if (k == 1 || k == n)
      cout << "-1\n";
    else
    {
      int p2 = k - k % 2;
      int p3 = k + 1 + k % 2;
      cout << "3\n1" << " " << p2 << " " << p3 << endl;
    }
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