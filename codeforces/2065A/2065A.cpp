#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  string s;
  cin >> s;
  if (s == "us")
  {
    cout << 'i' << "\n";
  }
  else
  {
    for (int i = 0; i < s.size(); i++)
    {
      if (i == s.size() - 2)
      {
        cout << 'i' << "\n";
        break;
      }
      else
      {
        cout << s[i] << "";
      }
    }
  }
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