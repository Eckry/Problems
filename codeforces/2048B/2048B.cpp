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
  vector<int> ans(n, 0);
  int count = 1;
  for (int i = k - 1; i < n; i += k)
  {
    ans[i] = count;
    count++;
  }

  int j = count;
  for (int i = 0; i < n; i++)
  {
    if (ans[i])
      continue;
    ans[i] = j;
    j++;
  }
  for (auto i : ans)
    cout << i << " ";
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