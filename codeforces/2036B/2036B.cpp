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
  vector<int> m(k + 1, 0);
  for (int i = 0; i < k; i++)
  {
    int x, y;
    cin >> x;
    cin >> y;
    m[x] += y;
  }
  sort(m.begin(), m.end());

  int i = m.size() - 1;
  long long int ans = 0;
  while (n--)
  {
    if(i < 0) break;
    ans += m[i];
    i--;
  }
  cout << ans << "\n";
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