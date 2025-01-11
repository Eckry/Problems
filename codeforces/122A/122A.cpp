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

  vector<int> a = {4, 7, 47, 74, 444, 447, 474, 477, 744, 747, 774, 777};
  for (int i = 0; i < a.size(); i++)
  {
    if (n % a[i] == 0)
    {
      cout << "YES" << "\n";
      return;
    }
  }
  cout << "NO" << "\n";
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