#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  long long n, m;
  cin >> n >> m;
  if (m < n)
  {
    cout << "NO" << "\n";
    return;
  }

  if (n & 1)
  {
    cout << "YES" << "\n";
    long long ans = m - n + 1;
    long long qua = m - ans;
    cout << ans << " ";
    for (int i = 0; i < qua; i++)
      cout << 1 << " ";
    cout << "\n";
  }
  else
  {
    if (m % n == 0)
    {
      cout << "YES" << "\n";
      for (int i = 0; i < n; i++)
      {
        cout << m / n << " ";
      }
      cout << "\n";
      return;
    }
    long long num = m / n;
    long long need = m - num * n;
    if (need & 1)
    {
      cout << "NO" << "\n";
      return;
    }
    cout << "YES" << "\n";
    long long pairs = need / 2;
    vector<long long> f;
    for (int i = 1; i <= n; i++)
    {
      f.push_back(num);
    }
    for (int i = 0; i < need; i++)
    {
      f[i]++;
    }

    for (auto c : f)
      cout << c << " ";
    cout << "\n";
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