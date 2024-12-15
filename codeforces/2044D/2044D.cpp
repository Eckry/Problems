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
  for (auto &i : a)
    cin >> i;

  vector<int> map(n + 1, 0);
  vector<int> b;
  int j = 1;
  for (int i = 0; i < n; i++)
  {
    if (!map[a[i]])
      map[a[i]] = 1;
    else
    {
      while (map[j])
        j++;
      b.push_back(j);
      map[j] = 1;
      continue;
    }
    b.push_back(a[i]);
  }

  for (auto i : b)
  {
    cout << i << " ";
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