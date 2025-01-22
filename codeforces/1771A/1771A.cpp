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
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;

  sort(a.begin(), a.end());
  long long mx = a[n - 1];
  long long mn = a[0];
  long long diff = abs(a[0] - a[n - 1]);

  int i = 1;
  int j = n - 2;

  long long cntmn = 1;
  long long cntmx = 1;
  while (i < n && a[i] == mn)
  {
    cntmn++;
    i++;
  }
  while (j >= 0 && a[j] == mx)
  {
    cntmx++;
    j--;
  }
  if (mx == mn)
  {
    cout << cntmx * (cntmx - 1) << "\n";
  }
  else
    cout << cntmn * cntmx * 2 << "\n";
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