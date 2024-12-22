#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n, m, k;
  cin >> n >> m >> k;

  vector<int> a(m);
  vector<int> q(n + 2, 0);

  for (auto &c : a)
    cin >> c;

  for (int i = 0; i < k; i++)
  {
    int temp;
    cin >> temp;
    q[temp] = 1;
  }

  if (k == n)
  {
    for (int i = 0; i < m; i++)
      cout << 1;
  }
  else if (k == n - 1)
  {
    for (int i = 0; i < m; i++)
      cout << 1 - q[a[i]];
    
  }
  else
  {
    for (int i = 0; i < m; i++)
      cout << 0;
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