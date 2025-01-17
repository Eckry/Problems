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
  vector<string> g(n);
  for (int i = 0; i < n; i++)
  {
    cin >> g[i];
  }

  vector<int> p(n);
  iota(p.begin(), p.end(), 0);

  sort(p.begin(), p.end(), [&](const int &u, const int &v) -> bool
       {
    if(g[u][v] == '1') return u < v;
    else return u>v; });

  for (auto c : p)
    cout << c + 1 << " ";
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