#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

vector<int> p;
vector<int> temp;
vector<bool> seen;
int ans;
void dfs(int cnt, int n)
{
  if (cnt == 0 && !seen[n] && n == p[n])
  {
    ans++;
    return;
  }
  if (n == p[n])
  {
    ans += cnt;
    return;
  }
  int x = p[n];
  seen[n] = 1;
  p[n] = n;
  dfs(cnt + 1, x);
}

void solve()
{
  int n;
  cin >> n;
  ans = 0;
  p = vector<int>(n + 1);
  for (int i = 1; i <= n; i++)
  {
    cin >> p[i];
  }
  temp = p;
  seen = vector<bool>(n + 1, 0);

  vector<int> d(n);
  for (auto &c : d)
    cin >> c;

  for (int i = 0; i < n; i++)
  {
    dfs(0, d[i]);
    cout << ans << " ";
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