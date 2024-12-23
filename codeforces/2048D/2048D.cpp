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
  vector<long long int> a(n);
  vector<long long int> b(m);

  for (auto &c : a)
    cin >> c;
  for (auto &c : b)
    cin >> c;

  long long int p = a[0];

  for (int i = 0; i < n; i++)
    if (a[i] < p)
      a[i] = p;
  for (int i = 0; i < m; i++)
    if (b[i] <= p)
      b[i] = 1e10;

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  vector<long long int> c(m);
  for (int i = 0; i < m; i++)
  {
    c[i] = n - (lower_bound(a.begin(), a.end(), b[i]) - a.begin());
  }

  sort(c.begin(), c.end());

  for (int i = 1; i <= m; i++)
  {
    long long int sum = 0;
    long long int j = 0;
    while (j < m / i)
    {
      sum += c[i * j + i - 1] + 1;
      j++;
    }
    cout << sum << " ";
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