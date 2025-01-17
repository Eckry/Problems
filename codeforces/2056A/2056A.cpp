#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n, m;
  cin >> n >> m;

  vector<vector<int>> paper(m, vector<int>(m));

  int x1, y1;
  cin >> x1 >> y1;
  int diffx = 0;
  int diffy = 0;
  for (int i = 1; i < n; i++)
  {
    int x2, y2;
    cin >> x2 >> y2;
    diffx += x2;
    diffy += y2;
  }

  cout << (diffx + m) * 2 + (diffy + m) * 2 << "\n";

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