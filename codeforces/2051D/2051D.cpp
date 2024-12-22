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
  long long int x, y;
  cin >> n >> x >> y;
  vector<long long int> a(n);
  long long int sum = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    sum += a[i];
  }

  sort(a.begin(), a.end());
  long long int count = 0;

  for (int i = 0; i < n; i++)
  {
    long long int k = a[i];
    auto z = upper_bound(a.begin() + i + 1, a.end(), sum - k - x);
    auto z2 = lower_bound(a.begin() + i + 1, a.end(), sum - y - k);
    count += z - z2;
  }
  cout << count << "\n";
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