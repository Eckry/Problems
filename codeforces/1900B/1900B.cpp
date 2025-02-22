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
  int a, b, c;
  cin >> a >> b >> c;
  if (abs(b - c) & 1)
    cout << 0 << " ";
  else
    cout << 1 << " ";
  if (abs(a - c) & 1)
    cout << 0 << " ";
  else
    cout << 1 << " ";
  if (abs(b - a) & 1)
    cout << 0 << " ";
  else
    cout << 1 << " ";
  cout << "\n";
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