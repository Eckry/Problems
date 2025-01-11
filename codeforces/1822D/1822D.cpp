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
  if (n == 1)
  {
    cout << 1 << "\n";
    return;
  }
  if (n & 1)
  {
    cout << -1 << "\n";
    return;
  }

  vector<int> h(n);
  int j = 0;
  int k = n - 1;
  for (int i = 0; i < n; i += 2)
  {
    h[i] = j++;
    h[i + 1] = k--;
  }

  cout << n << " ";
  int prev = 0;
  for (int i = 1; i < n; i++)
  {
    if (prev < h[i])
    {
      cout << h[i] - prev << " ";
    }
    else
    {
      cout << n + h[i] - prev << " ";
    }
    prev = h[i];
  }
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