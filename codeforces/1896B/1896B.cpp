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
  int end = n - 1;
  for (int i = n - 1; i >= 0; i--)
  {
    end = i;
    if (s[i] == 'B')
      break;
  }
  int start = 0;
  for (int i = 0; i <= end; i++)
  {
    start = i;
    if (s[i] == 'A')
      break;
  }
  cout << end - start << "\n";
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