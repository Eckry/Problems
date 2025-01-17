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
  vector<int> p(n);
  for (auto &c : p)
    cin >> c;

  int idx = 0;
  int mx = 0;
  int two = 0;

  for (int i = 0; i < n; i++)
  {
    if (p[i] == 1)
      idx = i;
    if (p[i] == n)
      mx = i;
    if (p[i] == 2)
      two = i;
  }
  if (idx == 0)
  {
    cout << 2 << " " << mx + 1 << "\n";
    return;
  }

  if (idx == n - 1)
  {
    cout << n - 1 << " " << mx + 1 << "\n";
    return;
  }

  if (idx < two)
  {
    if (mx < idx && mx < two)
    {
      cout << idx + 1 << " " << mx + 1 << "\n";
      return;
    }

    if (mx > idx && mx > two)
    {
      cout << two + 1 << " " << mx + 1 << "\n";
      return;
    }

    cout << 1 << " " << 1 << "\n";
  }
  else
  {
    if (mx < idx && mx < two)
    {
      cout << two + 1 << " " << mx + 1 << "\n";
      return;
    }

    if (mx > idx && mx > two)
    {
      cout << idx + 1 << " " << mx + 1 << "\n";
      return;
    }
    cout << 1 << " " << 1 << "\n";
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