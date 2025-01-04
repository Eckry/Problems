#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  long long int n, q;
  cin >> n >> q;

  vector<long long int> x(n);
  vector<long long int> k(q);
  for (auto &c : x)
    cin >> c;
  for (auto &c : k)
    cin >> c;

  map<long long int, long long int> m;

  for (long long int i = 0; i < n; i++)
  {
    if (i != n - 1)
      m[(i + 1) * (n - i - 1)] += x[i + 1] - x[i] - 1;
    m[(i + 1) * (n - i) - 1]++;
  }

  for (auto c : k)
    cout << m[c] << " ";

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