#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  long long int n, m;
  cin >> n >> m;
  vector<long long int> a(m);
  for (auto &c : a)
    cin >> c;

  vector<long long int> alive;

  sort(a.begin(), a.end());

  for (int i = 0; i < m - 1; i++)
  {
    if (a[i + 1] - a[i] - 1 > 0)
    {
      alive.push_back(a[i + 1] - a[i] - 1);
    }
  }

  if (a[0] + n - a[m - 1] - 1 > 0)
  {
    alive.push_back(a[0] + n - a[m - 1] - 1);
  }

  sort(alive.begin(), alive.end(), greater<long long int>());
  long long int count = 0;
  long long int saved = 0;
  for (int i = 0; i < alive.size(); i++)
  {
    if (alive[i] - count > 0)
    {
      if (alive[i] - count == 1)
      {
        saved++;
        break;
      }
      else
      {
        saved += alive[i] - count - 1;
        count += 4;
      }
    }
    else
      break;
  }

  cout << n - saved << "\n";
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