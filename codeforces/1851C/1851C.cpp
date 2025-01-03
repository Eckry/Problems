#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> c(n);
  for (auto &d : c)
    cin >> d;

  if (k == 1 || n == 1)
  {
    cout << "YES" << "\n";
    return;
  }

  map<int, int> m;
  int start = 0;
  int count = 1;
  for (int i = 1; i < n; i++)
  {
    if (c[i] == c[0])
      count++;
    start = i;
    if (count == k)
      break;
  }

  if (count < k)
  {
    cout << "NO" << "\n";
    return;
  }

  if (c[0] == c[n - 1])
  {
    cout << "YES" << "\n";
    return;
  }

  int count2 = 0;

  for (int i = start + 1; i < n; i++)
  {
    if (c[i] == c[n - 1])
      count2++;
  }

  if (count2 >= k)
    cout << "YES" << "\n";
  else
    cout << "NO" << "\n";
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