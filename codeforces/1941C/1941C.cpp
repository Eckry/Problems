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

  int counter = 0;

  for (int i = 0; i < n - 2; i++)
  {
    if (s[i] == 'm' && s[i + 1] == 'a' && s[i + 2] == 'p')
    {
      s[i + 2] = '*';
      counter++;
    }
    if (s[i] == 'p' && s[i + 1] == 'i' && s[i + 2] == 'e')
    {
      s[i] = '*';
      counter++;
    }
  }
  cout << counter << endl;
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