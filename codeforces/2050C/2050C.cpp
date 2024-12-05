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

  long long int sum = 0;
  long long int C2 = 0;
  long long int C3 = 0;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == '2')
      C2++;
    if (s[i] == '3')
      C3++;
    sum += s[i] - '0';
  }

  for (int i = 0; i <= C2; i++)
  {
    for (int j = 0; j <= C3; j++)
    {
      if ((sum + i * 2 + j * 6) % 9 == 0)
      {
        cout << "YES" << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
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