#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

int lcm(int a, int b)
{
  return (a * b) / __gcd(a, b);
}

void solve()
{
  long long n;
  cin >> n;
  vector<long long> k(n);
  for (auto &c : k)
    cin >> c;

  long long prev = 1;
  for (int i = 0; i < n; i++)
  {
    prev = lcm(prev, k[i]);
  }

  long long s = 0;

  for (int i = 0; i < n; i++)
  {
    s += prev / k[i];
  }

  if (s >= prev)
  {
    cout << -1 << "\n";
    return;
  }

  for (int i = 0; i < n; i++)
  {
    cout << prev / k[i] << " ";
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