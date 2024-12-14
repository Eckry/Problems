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
  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = n - 1; i > 0; i--)
  {
    int A;
    int B;
    if (a[i] < a[i - 1])
    {
      if (a[i - 1] < 10)
      {
        cout << "NO" << "\n";
        return;
      }

      A = a[i - 1] / 10;
      B = a[i - 1] % 10;
      if (B > a[i] || A > B)
      {
        cout << "NO" << "\n";
        return;
      }
      a[i - 1] = A;
    }
  }
  cout << "YES" << "\n";
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