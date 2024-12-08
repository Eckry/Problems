#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  long long int n, k;
  cin >> n >> k;
  if (k > pow(2, n - 1))
  {
    cout << -1 << endl;
    return;
  }

  vector<int> kB;
  k--;
  while (k)
  {
    kB.push_back(k % 2);
    k /= 2;
  }

  while (kB.size() < n - 1)
    kB.push_back(0);

  vector<int> a;
  vector<int> b;

  for (int i = n - 2, j = 1; i >= 0; i--, j++)
  {
    if (kB[i])
      b.push_back(j);
    else
      a.push_back(j);
  }

  for (int i = 0; i < a.size(); i++)
    cout << a[i] << " ";
  cout << n << " ";
  for (int i = b.size() - 1; i >= 0; i--)
    cout << b[i] << " ";
  cout << endl;
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