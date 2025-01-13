#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

int gcd(int a, int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int lcm(int a, int b)
{
  return (a / gcd(a, b)) * b;
}

void solve()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;

  vector<int> ans;
  ans.push_back(a[0]);

  for (int i = 0; i < n - 1; i++)
  {
    ans.push_back(lcm(a[i], a[i + 1]));
  }

  ans.push_back(a[n - 1]);

  for (int i = 0; i < n; i++)
  {
    if (gcd(ans[i], ans[i + 1]) != a[i])
    {
      cout << "NO" << "\n";
      return;
    }
  }
  cout << "YES" << "\n";
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