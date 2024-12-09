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
  int e = 0;
  vector<int> numb(n);
  int flg = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> numb[i];
    if(numb[i] % k == 0) flg = 1;
    if (numb[i] % 2 == 0)
      e++;
  }

  if (flg)
  {
    cout << 0 << endl;
    return;
  }

  int ans2 = INT_MAX;

  if (k == 4)
  {
    ans2 = max(0, 2 - e);
  }

  int ans = INT_MAX;

  for (int i = 0; i < n; i++)
  {
    int condition;
    if (k < numb[i])
      condition = k - numb[i] % k;
    else
      condition = k - numb[i];
    ans = min(ans, condition);
  }

  cout << min(ans, ans2) << endl;
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