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
  vector<long long> a(n);
  for (auto &c : a)
    cin >> c;

  long long mnM = INT_MAX;
  long long mnJ = INT_MAX;
  int idxM = 0;
  int idxJ = 1;

  if (n & 1)
    cout << "Mike" << "\n";
  else
  {
    for (int i = 0; i < n; i++)
    {
      if (i & 1)
      {
        if (mnJ > a[i])
        {
          mnJ = min(mnJ, a[i]);
          idxJ = i;
        }
      }
      else
      {
        if (mnM > a[i])
        {
          mnM = min(mnM, a[i]);
          idxM = i;
        }
      }
    }
    if (mnM < mnJ)
    {
      cout << "Joe" << "\n";
    }
    else if (mnM > mnJ)
    {
      cout << "Mike" << "\n";
    }
    else
    {
      if (idxM < idxJ)
        cout << "Joe" << "\n";
      else
        cout << "Mike" << "\n";
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