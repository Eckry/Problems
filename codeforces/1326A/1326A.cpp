#include <bits/stdc++.h>

using namespace std;

int solve()
{
  string n;
  cin >> n;
  int min = 0;
  char r[n.length()];
  map<char, int> hash;
  int x, y;
  for (int i = n.length() - 1; i >= 0; i--)
  {
    if (hash[n[i]] && (n[i] == '5' || n[i] == '0'))
    {
      return n.length() - x - 2 + x - i;
    }
    if (hash[n[i]] && (n[i] == '7' || n[i] == '2'))
    {
      return n.length() - y - 2 + y - i;
    }
    if (n[i] == '0')
    {
      hash['0'] = 1;
      hash['5'] = 1;
      x = i;
    }
    if (n[i] == '5')
    {
      hash['7'] = 1;
      hash['2'] = 1;
      y = i;
    }
  }
} //! 5 -> 0
  //! 0 -> 0
  //! 7 -> 5
  //! 2 -> 5

int main(void)
{
  int T;
  cin >> T;
  while (T--)
  {
    cout << solve() << endl;
  }
  return 0;
}