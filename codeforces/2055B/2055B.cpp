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
  vector<long long> b(n);
  for (auto &c : a)
    cin >> c;
  for (auto &c : b)
    cin >> c;

  long long diff = 0;
  int idx = 0;

  for (int i = 0; i < n; i++)
  {
    if (a[i] - diff >= b[i])
      continue;
    idx = i;
    diff = b[i] - a[i];
    break;
  }

  for (int i = 0; i < n; i++)
  {
    if (i == idx)
      continue;
    if (a[i] - diff < b[i])
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