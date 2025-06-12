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
  cout << (n - 3) * 2 + 3 << "\n";

  cout << 1 << " " << 2 << " " << n << "\n";
  for (int i = 0; i < n - 3; i++)
  {
    cout << i + 2 << " " << 1 << " " << i + 2 << "\n";
    cout << i + 2 << " " << i + 3 << " " << n << "\n";
  }
  cout << n - 1 << " " << 1 << " " << n - 1 << "\n";
  cout << n << " " << 1 << " " << n << "\n";
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