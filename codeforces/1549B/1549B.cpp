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
  string en;
  string gr;
  cin >> en >> gr;

  int count = 0;

  for (int i = 0; i < n; i++)
  {
    if (gr[i] == '1' && en[i] == '0')
    {
      gr[i] = '0';
      en[i] = '2';
      count++;
    }
  }

  for (int i = 0; i < n; i++)
  {
    if (gr[i] == '0')
      continue;
    if (i == 0)
    {
      if (en[i + 1] == '1')
      {
        en[i + 1] = '2';
        gr[i] = '0';
        count++;
        continue;
      }
    }
    if (i == n - 1)
    {
      if (en[i - 1] == '1')
      {
        en[i - 1] = '2';
        gr[i] = '0';
        count++;
        continue;
      }
    }
    if (en[i - 1] == '1')
    {
      en[i - 1] = '2';
      gr[i] = '0';
      count++;
    }
    else if (en[i + 1] == '1')
    {
      en[i + 1] = '2';
      gr[i] = '0';
      count++;
    }
  }

  cout << count << "\n";
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