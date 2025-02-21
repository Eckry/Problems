#include <bits/stdc++.h>

using namespace std;
#define ll long long
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
  int cnt = 0;
  int lst = -1;
  int fst = n - 1;
  for (int i = 0; i < n; i++)
  {
    if (s[i] == '1')
    {
      if (fst == n - 1)
        fst = i;
      cnt++;
      lst = i;
    }
  }
  if (cnt & 1 || (cnt == 2 && lst - fst == 1))
    cout << "NO" << "\n";
  else
    cout << "YES" << "\n";
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