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
  string ans = "";
  vector<char> vow = {'a', 'e', 'i', 'o', 'u'};

  int qnt = n / vow.size();
  if (qnt == 0)
  {
    for (int i = 0; i < n; i++)
    {
      ans += vow[i];
    }
    cout << ans << "\n";
    return;
  }

  int rst = n - qnt * vow.size();
  for (auto c : vow)
  {
    for (int i = 0; i < qnt; i++)
    {
      ans += c;
    }
    if (rst > 0)
    {
      ans += c;
      rst--;
    }
  }
  cout << ans << "\n";
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