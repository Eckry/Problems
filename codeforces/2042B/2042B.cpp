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
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;

  vector<int> acc(n + 1, 0);
  for (int i = 0; i < n; i++)
    acc[a[i]]++;

  ll unique = 0;
  ll nunique = 0;

  for (int i = 1; i <= n; i++)
  {
    if (acc[i] == 1)
      unique++;
    if (acc[i] > 1)
      nunique++;
  }
  unique = (unique + 1) / 2;
  cout << 2 * unique + nunique << "\n";
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