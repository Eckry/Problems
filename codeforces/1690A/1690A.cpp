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

  int h1 = n / 3;
  int h2 = n / 3;
  int h3 = n / 3;

  if (n - (h1 + h2 + h3) == 2)
  {
    h1 += 2;
    h3--;
    h2++;
  }
  else if (n - (h1 + h2 + h3) == 1)
  {
    h1 += 2;
    h2++;
    h3 -= 2;
  }
  else
  {
    h1++;
    h3--;
  }

  if (h3 == 0)
  {
    h3++;
    h2--;
  }

  cout << h2 << " " << h1 << " " << h3 << endl;
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