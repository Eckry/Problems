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
  string res;

  for (int i = 0; i < s.size() - 1; i++)
  {
    int max = s[i] - '0';
    int maxIndex = i;
    for (int j = 1; j < 10; j++)
    {
      if (i + j >= s.size())
        break;
      if (max < (s[i + j] - '0') - j)
      {
        max = (s[i + j] - '0') - j;
        maxIndex = j + i;
      }
    }

    for (int j = maxIndex; j > i; j--)
    {
      char temp = s[j];
      s[j] = s[j - 1];
      s[j - 1] = temp;
      s[j - 1]--;
    }
  }
  cout << s << endl;
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