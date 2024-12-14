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
  vector<string> a(2);
  cin >> a[0];
  cin >> a[1];

  for (int i = 0; i < n; i++)
  {
    if (a[0][i] == '1' && a[1][i] == '1') {
      cout << "NO" << endl;
      return;
    }
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