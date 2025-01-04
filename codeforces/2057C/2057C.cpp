#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  long long int l, r;
  cin >> l >> r;

  long long int a, b, c;
  long long int k = 31 - __builtin_clz(l ^ r);
  a = l | ((1 << k) - 1);
  b = a + 1;
  c = a == l ? r : l;

  cout << a << " " << b << " " << c << "\n";
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