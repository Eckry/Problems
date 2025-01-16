#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

bool isPrime(int n)
{
  for (int i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
      return false;
  }
  return true;
}

void solve()
{
  int n, m;
  cin >> n >> m;

  vector<vector<int>> a(n, vector<int>(m));
  int cnt = 1;
  for (int i = 0; i < n; i += 2)
  {
    for (int j = 0; j < m; j++)
    {
      a[i][j] = cnt++;
    }
  }

  for (int i = 1; i < n; i += 2)
  {
    for (int j = 0; j < m; j++)
    {
      a[i][j] = cnt++;
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << a[i][j] << " ";
    }
    cout << "\n";
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