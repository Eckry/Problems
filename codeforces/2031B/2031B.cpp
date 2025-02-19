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
  int n;
  cin >> n;
  vector<int> p(n);
  for (auto &c : p)
  {
    cin >> c;
  }

  for (int i = 0; i < n - 1; i++)
  {
    if (p[i] > p[i + 1] && abs(p[i] - p[i + 1]) == 1)
    {
      swap(p[i], p[i + 1]);
    }
  }
  if (is_sorted(p.begin(), p.end()))
  {
    cout << "YES" << "\n";
  }
  else
    cout << "NO" << "\n";
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