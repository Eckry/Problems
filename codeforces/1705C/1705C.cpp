#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n, c, q;
  cin >> n >> c >> q;
  vector<long long> left(c + 1);
  vector<long long> right(c + 1);
  vector<long long> diff(c + 1);

  string s;
  cin >> s;

  left[0] = 0;
  right[0] = n;

  for (int i = 1; i <= c; i++)
  {
    long long int l, r;
    cin >> l >> r;

    left[i] = right[i - 1];
    right[i] = left[i] + r - l + 1;
    diff[i] = left[i] - l + 1;
  }
  while (q--)
  {
    long long int k;
    cin >> k;

    for (int i = c; i > 0; i--)
    {
      if (k > left[i])
      {
        k -= diff[i];
      }
    }
    cout << s[k - 1] << "\n";
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