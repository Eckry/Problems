#include <bits/stdc++.h>

using namespace std;

long long int solve()
{
  long long int n, m;
  cin >> n >> m;
  long long int integersN[n];
  long long int integersM[m];
  for (int i = 0; i < n; i++)
    cin >> integersN[i];
  for (int i = 0; i < m; i++)
    cin >> integersM[i];

  for (int i = 0; i < m; i++)
  {
    long long int minX = 0;
    for (int j = 0; j < n; j++)
    {
      if (integersN[minX] > integersN[j])
      {
        minX = j;
      }
    }
    integersN[minX] = integersM[i];
  }
  long long int sum = 0;
  for(int i = 0; i < n ; i++) sum += integersN[i];
  return sum;
}

int main(void)
{
  int T;
  cin >> T;
  while (T--)
    cout << solve() << endl;
}