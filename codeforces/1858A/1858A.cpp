#include <bits/stdc++.h>

using namespace std;

string solve()
{
  int a, b, c;
  cin >> a >> b >> c;
  if (c % 2 + a > b)
    return "First";
  return "Second";
}

int main(void)
{
  int T;
  cin >> T;
  while (T--)
    cout << solve() << endl;
}