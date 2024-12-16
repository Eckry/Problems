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
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;

  sort(a.begin(), a.end());

  if (n == 2)
  {
    int temp = a[0];
    a[0] = a[1];
    a[1] = temp;
  }
  else
  {
    int temp0 = a[0];
    a[0] = a[1];
    a[1] = temp0;
    int temp = a[a.size() - 1];
    a[a.size() - 1] = a[0];
    a[0] = temp;
  }

  int ans = (a[0] - a[1]) * (a.size() - 1);
  cout << ans << "\n";
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