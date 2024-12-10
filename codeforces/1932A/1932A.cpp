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

  int coins = 0;
  int spikes = 0;

  for (int i = 0; i < n; i++)
  {
    if (s[i] == '@')
    {
      coins++;
    }
    if (s[i] == '*')
    {
      if(spikes) {
        cout << coins << endl;
        return;
      }
      spikes++;
    }
    else
    {
      spikes = 0;
    }
  }

  cout << coins << endl;
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