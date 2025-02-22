#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> b(n);
  for (auto &c : a)
    cin >> c;
  for (auto &c : b)
    cin >> c;
  ll mn = INT_MAX;
  for (auto c : a)
    mn = min(mn, c);
  ll op1 = 0;
  for (auto c : b)
  {
    op1 += mn + c;
  }
  mn = INT_MAX;
  for (auto c : b)
    mn = min(mn, c);
  ll op2 = 0;
  for (auto c : a)
  {
    op2 += mn + c;
  }
  cout << min(op1, op2) << "\n";
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