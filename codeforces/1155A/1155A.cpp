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
  char curr;
  char last;
  cin >> last;
  for (int i = 1; i < n; i++)
  {
    cin >> curr;
    if (last > curr)
    {
      cout << "YES" << endl;
      cout << i << " " << i + 1 << endl;
      return;
    } 
    last = curr;
  }
  cout << "NO";
  // for (int i = 0; i + 1 < n; i++)
  // {
  //   if (s[i] > s[i + 1])
  //   {
  //     cout << "YES" << endl;
  //     cout << i + 1 << " " << i + 2 << endl;
  //     return;
  //   }
  // }
  // cout << "NO";
}

int main(void)
{
  optimize()
      solve();
}