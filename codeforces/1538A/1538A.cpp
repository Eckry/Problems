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
  int stones[n];
  int max = 0, minN = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> stones[i];
    if (stones[max] < stones[i])
      max = i;
    if (stones[minN] > stones[i])
      minN = i;
  }

  int option1 = minN < max ? max + 1 : minN + 1;
  int option2 = minN < max ? n - minN : n - max;
  int option3 = minN < max ? minN + 1 + n - max : max + 1 + n - minN;

  int res = min(option1, option2);
  int res2 = min(res, option3);
  cout << res2 << endl;
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