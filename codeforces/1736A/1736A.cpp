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
  vector<int> b(n);

  int A1 = 0;
  int B1 = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    if (a[i] == 1)
      A1++;
  }
  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
    if (b[i] == 1)
      B1++;
  }

  int diff = 0;

  for (int i = 0; i < n; i++)
  {
    if (a[i] != b[i])
      diff++;
  }

  if (diff == 0)
  {
    cout << 0 << endl;
    return;
  }
  else if (diff && A1 - B1 == 0)
  {
    cout << 1 << endl;
    return;
  }
  else if (diff == abs(A1 - B1))
  {
    cout << diff << endl;
    return;
  }

  int ans = abs(A1 - B1);
  cout << ans + 1 << endl;
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