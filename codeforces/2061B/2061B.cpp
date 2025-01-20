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

  sort(a.begin(), a.end());

  map<long long, vector<int>> mp;
  long long equal = -1;
  long long equal2 = -1;
  for (int i = n - 1; i >= 0; i--)
  {
    mp[a[i]].push_back(i);
    if (mp[a[i]].size() == 2)
    {
      equal = mp[a[i]][0];
      equal2 = mp[a[i]][1];
      break;
    }
  }
  if (equal == -1)
  {
    cout << -1 << "\n";
    return;
  }

  int i = 0;
  int j = 0;
  long long mn = INT_MAX;
  for (int k = 0; k < n - 1; k++)
  {
    if (k + 1 == equal || k == equal2 || k + 1 == equal2 || k == equal)
      continue;
    long long diff = a[k + 1] - a[k];
    if (mn > diff)
    {
      mn = diff;
      i = k;
      j = k + 1;
    }
  }

  if (equal2 != 0 && equal != n - 1)
  {
    long long diff = a[equal + 1] - a[equal2 - 1];
    if (mn > diff)
    {
      i = equal + 1;
      j = equal2 - 1;
    }
  }

  if (a[equal] * 2 + min(a[i], a[j]) <= max(a[i], a[j]))
  {
    cout << -1 << "\n";
    return;
  }

  cout << a[equal] << " " << a[equal] << " " << a[i] << " " << a[j] << "\n";
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