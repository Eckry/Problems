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
  vector<int> p(n);
  for (auto &i : p)
    cin >> i;

  int count = 0;

  for (int i = 1; i <= k; i++)
  {
    if (p[i - 1] <= k)
      continue;
    count++;
  }

  cout << count << "\n";
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