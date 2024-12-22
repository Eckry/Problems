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

  vector<int> a(n);
  for (auto &i : a)
    cin >> i;

  int count = 0;
  int flg = 1;
  bool one = 0;
  for (int i = 0; i < n; i++)
  {
    if (flg && a[i] == 0)
    {
      count++;
      flg = 0;
    }
    else if (a[i] != 0)
    {
      flg = 1;
      one = 1;
    }
  }

  if (!one)
  {
    cout << 0 << "\n";
    return;
  }

  if (count > 2)
  {
    cout << 2 << "\n";
  }
  else if (count == 2 && a[0] == 0 && a[n - 1] == 0)
  {
    cout << 1 << "\n";
  }
  else if (count == 2)
  {
    cout << 2 << "\n";
  }
  else if (count == 1 && (a[0] == 0 || a[n - 1] == 0))
  {
    cout << 1 << "\n";
  }
  else if (count == 1)
  {
    cout << 2 << "\n";
  }
  else
  {
    cout << 1 << "\n";
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