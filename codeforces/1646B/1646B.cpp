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
  vector<long long int> a(n);
  for (auto &c : a)
    cin >> c;

  sort(a.begin(), a.end());

  long long int f = a[n - 1];
  long long int sm = a[0] + a[1];

  int i = 2;
  int j = n - 2;
  while (i < j && sm >= f) // 68 69
  {
    if(i == j) break;
    sm += a[i];
    f += a[j];
    j--;
    i++;
  }

  if (sm >= f)
  {
    cout << "NO" << "\n";
  }
  else
    cout << "YES" << "\n";
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