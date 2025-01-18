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
  for (auto &c : a)
    cin >> c;
  for (auto &c : b)
    cin >> c;

  vector<long long> diff(n);

  for (int i = 0; i < n; i++)
  {
    diff[i] = a[i] - 1 + b[i];
  }
  vector<int> idxAlice(n);
  iota(idxAlice.begin(), idxAlice.end(), 0);
  sort(idxAlice.begin(), idxAlice.end(), [&](int a, int b)
       { return diff[a] > diff[b]; });

  int i = 0;
  while (i < n - 1)
  {
    int ix = idxAlice[i];
    int ix2 = idxAlice[i + 1];
    a[ix]--;
    b[ix] = 0;
    a[ix2] = 0;
    b[ix2]--;

    i += 2;
  }
  if (i == n - 1)
  {
    int ix = idxAlice[i];
    a[ix]--;
    b[ix] = 0;
  }

  long long smA = 0;
  long long smB = 0;
  for (int i = 0; i < n; i++)
  {
    smA += a[i];
    smB += b[i];
  }

  cout << (smA - smB) << "\n";
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