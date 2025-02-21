#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n, m, k;
  cin >> n >> m >> k;

  vector<int> nums;
  for (int i = 0; i < n; i++)
  {
    nums.push_back(i % m);
  }
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    if (nums[i] != 0)
      cnt++;
  }
  if (k >= cnt)
  {
    cout << "NO" << "\n";
  }
  else
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