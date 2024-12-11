#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  if (k == 1)
  {
    for (int i = 0; i < n - 1; i++)
    {
      if(a[i] > a[i + 1]) {
        cout << "NO" << endl;
        return;
      }
    }
    cout << "YES" << endl;
    return;
  }

  cout << "YES" << endl;
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