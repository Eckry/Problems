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
    cin >> c;

  int ans = n - 1;
  int i = 0;
  vector<int> div;
  while (i < n)
  {
    if (p[i] == i + 1)
    {
      i++;
      continue;
    }
    div.push_back(abs(p[i] - i - 1));
    i++;
  }

  int res = div[0];
  for (auto c : div)
  {
    res = __gcd(res, c);
  }

  cout << res << "\n";
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