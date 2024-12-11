#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve() // 4 9 11
{
  long long int n, q;
  cin >> n >> q;
  vector<long long int> a(n);
  long long int o = 0;
  long long int e = 0;
  long long int sum = 0;
  for (long long int i = 0; i < n; i++)
  {
    cin >> a[i];
    sum += a[i];
    if (a[i] % 2 == 0)
    {
      e++;
    }
    else
    {
      o++;
    }
  }

  for (int i = 0; i < q; i++)
  {
    long long int op;
    long long int x;
    cin >> op >> x;

    if (op == 1)
    {
      sum += o * x;
      if (x % 2 == 1)
      {
        e += o;
        o = 0;
      }
    }
    else
    {
      sum += e * x;
      if (x % 2 == 1)
      {
        o += e;
        e = 0;
      }
    }
    cout << sum << endl;
  }
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