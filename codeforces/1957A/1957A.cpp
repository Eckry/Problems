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
  int numbers[n];
  vector<int> res(101, 0);

  for (int i = 0; i < n; i++)
  {
    cin >> numbers[i];

    res[numbers[i]]++;
  }

  int counter = 0;

  for (int i = 0; i < 101; i++)
  {
    if (res[i] < 3)
      continue;
    counter += res[i] / 3;
  }

  cout << counter << "\n";
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