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
  vector<int> ans;
  for (int i = n; i > m; i--)
  {
    ans.push_back(i);
  }
  for (int i = 1; i <= m; i++)
  {
    ans.push_back(i);
  }
  for(auto c : ans) cout << c << " ";
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