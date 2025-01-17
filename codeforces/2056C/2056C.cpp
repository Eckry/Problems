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
  vector<int> ans(n);

  ans[0] = 1;
  for (int i = 1; i <= n - 6; i++)
  {
    ans[i] = 3 + i;
  }

  ans[n - 5] = 1;
  ans[n - 4] = 2;
  ans[n - 3] = 3;
  ans[n - 2] = 1;
  ans[n - 1] = 2;
  for (auto c : ans)
    cout << c << " ";
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