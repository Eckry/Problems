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
  long long int length = n * (n - 1) / 2;
  long long int mx = INT_MIN;
  vector<long long int> b(length);
  map<long long int, long long int> m;
  for (long long int i = 0; i < length; i++)
  {
    cin >> b[i];
    m[b[i]]++;
    mx = max(mx, b[i]);
  }

  vector<long long int> ans;
  long long int i = 0;
  for (auto c : m)
  {
    long long int mn = n - 1 - i;
    while (c.second != mn)
    {
      c.second -= mn;
      mn--;
      ans.push_back(c.first);
      i++;
    }
    ans.push_back(c.first);
    i++;
  }

  ans.push_back(mx);
  for (auto c : ans)
    cout << c << " ";
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