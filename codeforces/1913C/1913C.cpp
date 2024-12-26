#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int m;
  cin >> m;
  vector<long long int> n(30, 0);

  while (m--)
  {
    int t;
    cin >> t;
    if (t == 1)
    {
      int v;
      cin >> v;
      n[v]++;
    }
    else
    {
      long long int v;
      cin >> v;
      for (long long int i = 29; i >= 0; i--)
      {
        if ((1 << i) <= v)
        {
          long long int x = v / (1 << i);
          if (x > n[i])
            x = n[i];
          v -= x * (1 << i);
        }
      }
      if (v == 0)
      {
        cout << "YES" << "\n";
      }
      else
      {
        cout << "NO" << "\n";
      }
    }
  }
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