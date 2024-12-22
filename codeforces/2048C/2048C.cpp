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
  int cero = -1;

  vector<int> y = {0, 0};
  vector<vector<int>> XOR(2, y);

  XOR[0][0] = 0;
  XOR[1][0] = 1;
  XOR[0][1] = 1;
  XOR[1][1] = 0;

  string s1 = s;
  int n = s.size();
  bool one = 0;
  for (int i = 0; i < n; i++)
  {
    if (s[i] == '1')
    {
      one = 1;
    }
    if (s[i] == '0')
    {
      cero = i;
      break;
    }
  }

  if (!one)
  {
    cout << 1 << " " << 1 << " " << 1 << " " << 1 << "\n";
    return;
  }

  if (cero == -1)
  {
    cout << 1 << " " << n << " " << 1 << " " << 1 << "\n";
    return;
  }

  string mx = "0";
  int mxL = 1;
  int mxR = 1;
  int start = cero - (n - cero) > 0 ? cero - (n - cero) : 0;
  string s2 = s.substr(0, n - cero);
  int n2 = s2.size();
  for (int i = 0; i <= cero; i++)
  {
    string newmx = "";
    for (int k = 0; k < s2.size(); k++)
    {

      if (XOR[s2[n2 - k - 1] - '0'][s1[n - k - 1] - '0'])
      {
        newmx = '1' + newmx;
      }
      else
      {
        newmx = '0' + newmx;
      }
    }

    if (newmx > mx)
    {
      mxL = i;
      mxR = i + n - cero;
      mx = newmx;
    }

    s2.erase(0, 1);
    s2 += s[n - cero + i];
  }

  cout << 1 << " " << n << " " << mxL + 1 << " " << mxR << "\n";
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