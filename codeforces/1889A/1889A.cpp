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

  int k = 300;
  vector<int> ans;
  while (k--)
  {
    bool flg = 1;
    int idx;
    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == s[s.size() - i - 1])
      {
        idx = i;
        flg = 0;
        break;
      }
    }
    if (flg)
      break;
    string newS;
    if (s[idx] == '0')
    {
      newS = s.substr(0, s.size() - idx) + "01" + s.substr(s.size() - idx, idx);
      ans.push_back(s.size() - idx);
    }
    else
    {
      newS = s.substr(0, idx) + "01" + s.substr(idx, s.size() - idx);
      ans.push_back(idx);
    }
    s = newS;
  }

  for (int i = 0; i < s.size(); i++)
    if (s[i] == s[s.size() - i - 1])
    {
      cout << -1 << "\n";
      return;
    }

  cout << ans.size() << "\n";
  for (auto c : ans)
  {
    cout << c << " ";
  }
  cout << "\n";
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