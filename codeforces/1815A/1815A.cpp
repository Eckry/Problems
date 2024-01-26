#include <bits/stdc++.h>

using namespace std;

string solve()
{
  int n;
  cin >> n;
  long long int a[n];
  for (long long int i = 0; i < n; i++)
  {
    cin >> a[i];
    if (i == 0)
      continue;
    a[i] += a[0] - a[i - 1];
  }

  if (n % 2 != 0)
    return "YES";
  if (a[n - 1] < a[0])
    return "NO";
  return "YES";
}

int main(void)
{
  int T;
  cin >> T;
  while (T--)
  {
    cout << solve() << endl;
  }
  return 0;
}