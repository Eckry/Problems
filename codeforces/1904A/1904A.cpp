#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  long long int a, b;
  cin >> a >> b;
  long long int xk, yk;
  cin >> xk >> yk;
  long long int xq, yq;
  cin >> xq >> yq;

  set<pair<int, int>> st1, st2;
  int dx[4] = {-1,
               1,
               -1,
               1};
  int dy[4] = {-1,
               -1,
               1,
               1};
  for (int i = 0; i < 4; i++)
  {
    st1.insert({xk + dx[i] * a, yk + dy[i] * b});
    st2.insert({xq + dx[i] * a, yq + dy[i] * b});
    st1.insert({xk + dx[i] * b, yk + dy[i] * a});
    st2.insert({xq + dx[i] * b, yq + dy[i] * a});
  }

  int ans = 0;
  for (auto i : st1)
  {
    if (st2.find(i) != st2.end())
    {
      ans++;
    }
  }
  cout << ans << "\n";
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