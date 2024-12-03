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
  long long int count = 0;
  long long int q;
  cin >> q;

  for (long long int j = 0; j < s.size() - 3; j++)
  {
    if (s[j] == '1' && s[j + 1] == '1' && s[j + 2] == '0' && s[j + 3] == '0')
    {
      count++;
    }
  }

  if (s.size() < 4)
    for (long long int i = 0; i < q; i++)
    {
      long long int j;
      char v;
      cin >> j;
      cin >> v;
      cout << "NO" << endl;
    }
  else
    while (q--)
    {
      long long int before = 0;

      long long int i;
      char v;
      cin >> i;
      cin >> v;

      long long int condition = i + 2 > s.size() ? s.size() - 3 : i;

      for (long long int j = i - 4 < 0 ? 0 : i - 4; j < condition; j++)
      {
        if (s[j] == '1' && s[j + 1] == '1' && s[j + 2] == '0' && s[j + 3] == '0')
        {
          before++;
        }
      }

      s[i - 1] = v;

      long long int after = 0;

      for (long long int j = i - 4 < 0 ? 0 : i - 4; j < condition; j++)
      {
        if (s[j] == '1' && s[j + 1] == '1' && s[j + 2] == '0' && s[j + 3] == '0')
        {
          after++;
        }
      }

      count += after - before;
      if (count > 0)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
}

int main(void)
{
  optimize();
  long long int T;
  cin >> T;
  // T = 1;
  while (T--)
    solve();
}