#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

vector<int> solve2(int n, int k)
{
  vector<int> ans(n);
  if (n == 0)
    return {};
  if (k < n)
  {
    for (int i = 0; i < n; i++)
    {
      ans[i] = -1;
    }
    if (k != 0)
      ans[k - 1] = 200;
    ans[k] = -400;
  }
  else
  {
    ans = solve2(n - 1, k - n);
    ans.push_back(1000);
  }
  return ans;
}

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> ans = solve2(n, k);
  for (auto c : ans)
  {
    cout << c << " ";
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