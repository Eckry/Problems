#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  int n, t;
  cin >> n >> t;

  int min = 10000000;
  int route = 1;

  for (int i = 0; i < n; i++)
  {
    int s, d;
    cin >> s >> d;

    if (s == t)
    {
      route = i + 1;
      break;
    }

    int curr = 0;

    if (s > t)
      curr = s;
    else
    {
      int temp;
      if ((t - s) % d == 0) temp = (t - s) / d;
      else temp = (t - s) / d + 1;
      curr = s + temp * d;
    }

    if (curr < min)
    {
      min = curr;
      route = i + 1;
    }
  }
  cout << route;
}