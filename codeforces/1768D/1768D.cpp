#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

vector<int> visited;
vector<int> a;
int cycles;
void dfs(int n)
{
  if (visited[n] != -1)
  {
    return;
  }
  visited[n] = cycles;
  dfs(a[n]);
}

void solve()
{
  int n;
  cin >> n;
  a = vector<int>(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  visited = vector<int>(n + 1, -1);
  cycles = 0;
  for (int i = 1; i <= n; i++)
  {
    if (visited[i] != -1)
      continue;
    cycles++;
    dfs(i);
  }

  for (int i = 1; i < n; i++)
  {
    if (visited[i] == visited[i + 1])
    {
      cout << abs(n - cycles - 1) << "\n";
      return;
    }
  }

  cout << abs(n - cycles + 1) << "\n";
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
