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
  string s;
  cin >> s;
  int n = s.size();
  for (int i = 0; i < n - 1; i++)
  {
    if(s[i] == s[i + 1]){
      cout << 1 << "\n";
      return;
    }
  }
  cout << n << "\n";
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