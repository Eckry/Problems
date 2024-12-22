#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n, m;
  cin >> n >> m;
  map<long long int, vector<long long int>> w;
  map<long long int, long long int> idx;
  for (int i = 0; i < m; i++)
  {
    long long int x1;
    long long int w1;
    cin >> x1;
    cin >> w1;
    w[w1].push_back(x1);
    idx[x1] = i + 1;
  }

  long long int sum = 0;
  long long int count = 0;
  vector<long long int> pos(n * 2);
  for (auto i : w)
  {
    for (auto j : i.second)
    {
      if (count >= n * 2)
        break;
      sum += i.first;
      pos[count] = j;
      count++;
    }
    if (count >= n * 2)
      break;
  }

  sort(pos.begin(), pos.end());
  cout << sum << "\n";
  for (int i = 0; i < n; i++)
  {
    cout << idx[pos[i]] << " ";
    cout << idx[pos[2 * n - i - 1]] << "\n";
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