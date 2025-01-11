#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int k, q;
  cin >> k >> q;
  vector<int> a(k);
  for (auto &c : a)
    cin >> c;

  while (q--)
  {
    int i;
    cin >> i;
    if (i > a[0])
    {
      cout << a[0] - 1 << " ";
    }
    else if (i < a[0])
    {
      cout << i << " ";
    }
    else
    {
      cout << i - 1 << " ";
    }
  }
  cout << "\n";
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