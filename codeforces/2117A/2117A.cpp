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
  int n, x;
  cin >> n >> x;

  vector<int> a(n);
  for (auto &c : a)
    cin >> c;

  int pos = 0;
  for (; pos < n && a[pos] == 0; pos++)
    ;

  pos += x;
  for (; pos < n && a[pos] == 0; pos++)
    ;

  if (pos > n - 1)
  {
    cout << "YES" << "\n";
  }
  else
    cout << "NO" << "\n";
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