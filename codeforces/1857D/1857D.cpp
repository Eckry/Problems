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
  vector<long long int> b(n);
  for (auto &c : a)
    cin >> c;
  for (auto &c : b)
    cin >> c;

  vector<long long int> diff(n);
  map<long long int, vector<long long int>> m;
  for (int i = 0; i < n; i++)
  {
    diff[i] = a[i] - b[i];
    m[diff[i]].push_back(i + 1);
  }

  sort(diff.begin(), diff.end());
  int ans = 0;
  int i = n - 1;

  while (diff[i] == diff[n - 1])
  {
    i--;
    ans++;
  }
  cout << ans << "\n";
  sort(m[diff[n - 1]].begin(), m[diff[n - 1]].end());
  for (auto c : m[diff[n - 1]])
  {
    cout << c << " ";
  }
  cout << "\n";
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