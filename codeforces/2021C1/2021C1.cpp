#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n, m, q;
  cin >> n >> m >> q;

  vector<int> a(n);
  vector<int> b(m);
  for (auto &c : a)
    cin >> c;
  for (auto &c : b)
    cin >> c;

  map<int, bool> ap;

  int j = 0;
  for (int i = 0; i < m; i++)
  {
    if (ap[b[i]])
      continue;
    if (b[i] != a[j] && !ap[a[j]])
    {
      cout << "TIDAK" << "\n";
      return;
    }
    ap[a[j]] = 1;
    if (a[j] == b[i])
    {
      j++;
    }
  }

  cout << "YA" << "\n";
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