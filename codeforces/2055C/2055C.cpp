#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<vector<long long>> a(n, vector<long long>(m));
  for (auto &c : a)
    for (auto &b : c)
      cin >> b;

  vector<long long> smR(n);
  vector<long long> smC(m);

  for (int i = 0; i < n; i++)
  {
    long long int sm = 0;
    for (int j = 0; j < m; j++)
    {
      sm += a[i][j];
    }
    smR[i] = sm;
  }

  for (int j = 0; j < m; j++)
  {
    long long int sm = 0;
    for (int i = 0; i < n; i++)
    {
      sm += a[i][j];
    }
    smC[j] = sm;
  }

  long long mx = 0;

  int i = 0;
  int j = 0;
  int k = 0;
  while (1)
  {
    long long diff;
    if (k == s.size())
    {
      diff = mx - smC[j];
    }
    else if (s[k] == 'R')
    {
      diff = mx - smC[j];
    }
    else
      diff = mx - smR[i];

    smC[j] += diff;
    smR[i] += diff;
    a[i][j] = diff;

    if (k == s.size())
      break;
    if (s[k] == 'R')
    {
      j++;
    }
    else
    {
      i++;
    }
    k++;
  }

  for (auto it1 : a)
  {
    for (auto it2 : it1)
      cout << it2 << " ";
    cout << "\n";
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