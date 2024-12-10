#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  string s;
  cin >> s;

  int n = s.size();
  if (n < 4)
  {
    cout << "YES" << endl;
    return;
  }

  int zero = 0;
  int one = 0;

  int idxZ = -1;
  int idxO = -1;

  for (int i = 0, j = n - 1; i < n; i++, j--)
  {
    if (s[i] == '1')
    {
      if (one && idxO == -1)
        idxO = i;
      one = 1;
    }
    else
    {
      one = 0;
    }
    if (s[j] == '0')
    {
      if (zero && idxZ == -1)
        idxZ = j;
      zero = 1;
    }
    else
    {
      zero = 0;
    }
  }

  if (idxZ == -1 | idxO == -1)
    cout << "YES" << endl;
  else if (idxO < idxZ)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
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