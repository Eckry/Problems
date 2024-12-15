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
  vector<long long int> a(n);
  for (auto &i : a)
    cin >> i;

  int count = 0;
  bool zero = 0;

  for (int i = 0; i < n; i++)
  {
    if (a[i] < 0)
    {
      count++;
    }
    if (a[i] == 0)
    {
      zero = 1;
    }
  }

  long long int sum = 0;
  if (zero)
  {
    for (int i = 0; i < n; i++)
      sum += abs(a[i]);
    cout << sum << "\n";
    return;
  }
  vector<long long int> b;
  for (int i = 0; i < n; i++)
  {
    b.push_back(abs(a[i]));
  }
  sort(b.begin(), b.end());

  for (int i = 0; i < n; i++) // 2 1 8 5 -1 -5 8
  {
    if (count % 2 == 0)
    {
      sum += abs(b[i]);
    }
    else
    {
      if (i == 0)
        sum += abs(b[i]) * (-1);
      else
        sum += abs(b[i]);
    }
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