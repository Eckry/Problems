#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  int T;
  cin >> T;
  while (T--)
  {
    long double x, y, k;
    cin >> x >> y >> k;

    long double T1 = k * y;
    long double P1 = ceil(T1 / (x - 1));
    long double sticksLeft = P1 * (x - 1) - T1 + 1;
    long double L;
    if (sticksLeft < k)
    {
      long double sticksNeeded = k - sticksLeft;
      L = ceil(sticksNeeded / (x - 1));
    }
    else
    {
      L = 0;
    }
    cout << (long long int)P1 + (long long int)L + (long long int)k << endl;
  }
}