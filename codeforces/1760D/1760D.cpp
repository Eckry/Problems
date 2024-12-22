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

  for (auto &c : a)
    cin >> c;

     if (n == 1)
  {
    cout << "YES" << "\n";
    return;
  }

  bool flg = 0;

  int i = 0;
  while (a[i] >= a[i + 1] && i < n - 1)
  {
    i++;
  }

  int j = n - 1;
  while (a[j - 1] <= a[j] && j > 0)
  {
    if (j == i)
      break;
    j--;
  }

  if (j == i)
  {
    cout << "YES" << "\n";
  }
  else
  {
    cout << "NO" << "\n";
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