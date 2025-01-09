#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

bool check(vector<int> &d, int mid, int ori)
{
  vector<int> freq(21, 0);
  for (int i = 0; i < mid; i++)
  {
    int x = d[i];
    int j = 0;
    while (x)
    {
      if (x & 1)
        freq[j]++;
      x >>= 1;
      j++;
    }
  }
  int or2 = 0;
  for (int i = 0; i < 21; i++)
  {
    if (freq[i])
    {
      or2 |= (1 << i);
    }
  }

  if (or2 != ori)
    return false;

  for (int i = 0; i + mid < d.size(); i++)
  {
    int x = d[i];
    int j = 0;
    while (x)
    {
      if (x & 1)
      {
        freq[j]--;
        if (freq[j] == 0)
        {
          or2 -= (1 << j);
        }
      }
      x >>= 1;
      j++;
    }

    x = d[i + mid];
    j = 0;
    while (x)
    {
      if (x & 1)
      {
        freq[j]++;
        if (freq[j] == 1)
          or2 += (1 << j);
      }
      x >>= 1;
      j++;
    }
    if (or2 != ori)
      return false;
  }

  return true;
}

void solve()
{
  int n;
  cin >> n;
  vector<int> a(n);
  int ori = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    ori |= a[i];
  }

  int l = 1;
  int r = n;

  while (l < r)
  {
    int mid = (l + r) / 2;
    if (check(a, mid, ori))
    {
      r = mid;
    }
    else
    {
      l = mid + 1;
    }
  }

  cout << l << "\n";
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