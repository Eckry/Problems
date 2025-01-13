#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

bool isPrime(int n)
{
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0)
      return 0;
  return 1;
}

void solve()
{
  int n;
  cin >> n;
  int l = 0;
  vector<int> ans;
  for (int i = 1; i <= n; i += 2)
  {
    l = i;
    ans.push_back(i);
  }
  int idx = -1;
  for (int i = 2; i <= n; i += 2)
  {
    if (!isPrime(l + i))
    {
      idx = i;
      break;
    }
  }

  if (idx == -1)
  {
    cout << -1 << "\n";
    return;
  }

  for (auto c : ans)
    cout << c << " ";

  for (int i = idx; i <= n; i += 2)
  {
    cout << i << " ";
  }

  for (int i = 2; i < idx; i += 2)
    cout << i << " ";
  // 1 3 5 7 2 4 6 8
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