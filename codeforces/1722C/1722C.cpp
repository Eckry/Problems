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

  map<string, int> fi;
  map<string, int> se;
  map<string, int> th;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < n; j++)
    {
      string s;
      cin >> s;
      if (i == 0)
      {
        fi[s] = 3;
        continue;
      }
      if (i == 1)
      {
        if (fi[s])
        {
          fi[s] -= 2;
          se[s] = 1;
        }
        else
        {
          se[s] = 3;
        }
      }
      if (i == 2)
      {
        if (fi[s] && se[s])
        {
          fi[s] -= 2;
          se[s] -= 2;
          th[s] = -1;
        }
        else if (fi[s])
        {
          fi[s] -= 2;
          th[s] = 1;
        }
        else if (se[s])
        {
          se[s] -= 2;
          th[s] = 1;
        }
        else
        {
          th[s] = 3;
        }
      }
    }
  }
  vector<int> ans(3, 0);
  for (auto i : fi)
    ans[0] += max(0, i.second);
  for (auto i : se)
    ans[1] += max(0, i.second);
  for (auto i : th)
    ans[2] += max(0, i.second);
  for (int i = 0; i < 3; i++)
    cout << ans[i] << " ";
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