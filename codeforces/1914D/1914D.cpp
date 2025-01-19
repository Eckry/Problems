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
  vector<long long> a(n);
  vector<long long> b(n);
  vector<long long> c(n);
  for (auto &d : a)
    cin >> d;
  for (auto &d : b)
    cin >> d;
  for (auto &d : c)
    cin >> d;

  vector<int> idsA(n);
  vector<int> idsB(n);
  vector<int> idsC(n);
  iota(idsA.begin(), idsA.end(), 0);
  iota(idsB.begin(), idsB.end(), 0);
  iota(idsC.begin(), idsC.end(), 0);

  sort(idsA.begin(), idsA.end(), [&](int l, int r)
       { return a[l] > a[r]; });
  sort(idsB.begin(), idsB.end(), [&](int l, int r)
       { return b[l] > b[r]; });
  sort(idsC.begin(), idsC.end(), [&](int l, int r)
       { return c[l] > c[r]; });

  long long ans = INT_MIN;

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      for (int k = 0; k < 3; k++)
      {
        if (idsA[i] != idsB[j] && idsA[i] != idsC[k] && idsB[j] != idsC[k])
        {
          ans = max(ans, a[idsA[i]] + b[idsB[j]] + c[idsC[k]]);
        }
      }
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