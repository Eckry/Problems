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
  string s;
  cin >> s;
  vector<int> a(n);
  bool zero = 1;
  bool one = 1;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    if (s[i] == '1')
      zero = 0;
    if (s[i] == '0')
      one = 0;
  }

  if (zero)
  {
    cout << 0 << "\n";
    return;
  }

  if (one)
  {
    long long int sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum += a[i];
    }
    cout << sum << "\n";
    return;
  }

  if (n == 1)
  {
    cout << a[0] * (s[0] - '0') << "\n";
    return;
  }

  long long int sum = 0;
  bool flg = 0;
  int m;
  for (int i = 0; i < n - 1; i++)
  {
    if (!flg && s[i] == '1' && s[i + 1] == '0')
    {
      sum += a[i];
    }
    if (!flg && s[i] == '1' && s[i + 1] == '1')
    {
      sum += a[i];
    }
    if (s[i] == '0' && s[i + 1] == '1')
    {
      sum += a[i];
      m = a[i];
      flg = 1;
    }
    if (flg && s[i] == '1' && s[i + 1] == '0')
    {
      flg = 0;
      sum += a[i];
      m = min(m, a[i]);
      sum -= m;
    }
    if (flg && s[i] == '1' && s[i + 1] == '1')
    {
      sum += a[i];
      m = min(m, a[i]);
    }
  }

  if (flg)
  {
    sum += a[n - 1];
    m = min(m, a[n - 1]);
    sum -= m;
  }

  cout << sum << "\n";
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