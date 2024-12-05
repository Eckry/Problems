#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  long long int n;
  cin >> n;
  long long int a[n];

  long long int e = 0;
  long long int o = 0;
  long long int sumE = 0;
  long long int sumO = 0;

  for (long long int i = 0; i < n; i++)
  {
    cin >> a[i];
    if (i % 2 == 0)
    {
      e++;
      sumE += a[i];
    }
    else
    {
      o++;
      sumO += a[i];
    }
  }

  if(sumO % o != 0) {cout << "NO" << endl; return;}
  if(sumE % e != 0) {cout << "NO" << endl; return;}

  long long int avgO = sumO / o;
  long long int avgE = sumE / e;
  if (avgE == avgO)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
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