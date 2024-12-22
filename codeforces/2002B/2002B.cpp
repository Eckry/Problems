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
  vector<int> b(n);
  for (auto &i : a)
    cin >> i;
  for (auto &i : b)
    cin >> i;

  int i = 0;
  int j = n - 1;
  int I = 0;
  int J = n - 1;
  while (i <= j && I <= J)
  {
    if (a[i] != b[I] && a[i] != b[J])
    {
      cout << "Alice" << "\n";
      return;
    }
    if (a[j] != b[I] && a[j] != b[J])
    {
      cout << "Alice" << "\n";
      return;
    }

    if (a[i] == b[I])
    {
      i++;
      I++;
      continue;
    }
    if (a[i] == b[J])
    {
      i++;
      J--;
      continue;
    }
    if (a[j] == b[I])
    {
      I++;
      j--;
      continue;
    }
    if (a[j] == b[J])
    {
      j--;
      J--;
      continue;
    }
  }
  cout << "Bob" << "\n";
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