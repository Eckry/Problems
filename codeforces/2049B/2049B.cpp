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
  string s;
  cin >> s;

  // p -> 1 - i
  // s -> i - n

  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (s[i] == 's')
      {
        if (s[j] == 'p')
        {
          if (i == 0 || j == n - 1)
            continue;
          cout << "NO" << "\n";
          return;
        }
      }
      if(s[i] == 'p') {
        if(s[j] == 's') {
          cout << "NO" << "\n";
          return;
        }
      }
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