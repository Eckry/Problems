#include <bits/stdc++.h>

using namespace std;
#define ll long long
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
  {
    int x;
    cin >> x;
    a[i] = abs(x);
  }
  int target = a[0];
  sort(a.begin(), a.end());

  int idx = 0;
  for (int i = 0; i < n; i++)
  {
    idx = i;
    if (target == a[i])
    {
      break;
    }
  }

  if (idx <= n / 2)
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