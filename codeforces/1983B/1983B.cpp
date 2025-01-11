#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n, m;
  cin >> n >> m;

  vector<string> a(n);
  vector<string> b(n);

  for (auto &c : a)
    cin >> c;
  for (auto &c : b)
    cin >> c;

  vector<int> smHA(n);
  vector<int> smHB(n);
  vector<int> smVA(m);
  vector<int> smVB(m);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      smHA[i] += (a[i][j] - '0');
      smHB[i] += (b[i][j] - '0');
    }
  }

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      smVA[i] += (a[j][i] - '0');
      smVB[i] += (b[j][i] - '0');
    }
  }

  for (int i = 0; i < n; i++)
  {
    if ((smHA[i] % 3) != (smHB[i] % 3))
    {
      cout << "NO" << "\n";
      return;
    }
  }

  for (int i = 0; i < m; i++)
  {
    if ((smVA[i] % 3) != (smVB[i] % 3))
    {
      cout << "NO" << "\n";
      return;
    }
  }

  cout << "YES" << "\n";
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