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
  long long int numbers[n];

  for (int i = 0; i < n; i++)
  {
    cin >> numbers[i];
  }

  for (int i = 1; i < n - 1; i++)
  {
    if (numbers[i - 1] < 0)
    {
      cout << "NO" << endl;
      return;
    }

    numbers[i + 1] -= numbers[i - 1];
    numbers[i] -= numbers[i - 1] * 2;
    numbers[i - 1] = 0;
  }

  if (numbers[n - 1] != 0 || numbers[n - 2] != 0)
  {
    cout << "NO" << endl;
  }
  else
  {
    cout << "YES" << endl;
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