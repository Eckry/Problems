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
  for (auto &c : a)
    cin >> c;

  long long count = 0;

  for (int i = 0; i < n; i++)
  {
    while (a[i])
    {
      if (a[i] % 2 == 0)
        count++;
      else
        break;
      a[i] /= 2;
    }
  }

  if (count < n)
  {
    vector<long long> twos;

    for (int i = 2; i <= n; i += 2)
    {
      int j = i;
      long long cnt = 0;
      while (j)
      {
        if (j & 1)
          break;
        else
          cnt++;
        j /= 2;
      }

      twos.push_back(cnt);
    }
    sort(twos.begin(), twos.end());
    for (int i = twos.size() - 1; i >= 0; i--)
    {
      count += twos[i];
      if (count >= n)
      {
        cout << twos.size() - i << "\n";
        return;
      }
    }
    cout << -1 << "\n";
  }
  else
    cout << 0 << "\n";
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