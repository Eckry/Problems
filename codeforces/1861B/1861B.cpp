#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  string a, b;
  cin >> a;
  cin >> b;

  int n = a.size();

  for (int i = 0; i < n - 1; i++)
  {
    if (a[i] == '0' && b[i] == '0')
    {
      if (a[i + 1] == '1' && b[i + 1] == '1')
      {
        cout << "YES" << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
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