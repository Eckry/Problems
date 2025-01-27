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
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;
  if (a[a.size() - 1] < a[0])
    reverse(a.begin(), a.end());
  ll sm = 0;
  for (auto c : a)
    sm += c;
  ll res = sm;
  while (a.size() != 1)
  {
    vector<ll> ans;
    sm = 0;
    for (int i = 1; i < a.size(); i++)
      ans.push_back(a[i] - a[i - 1]);

    a = ans;
    if (a[a.size() - 1] < a[0])
      reverse(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++)
      sm += a[i];
    res = max(sm, res);
  }
  cout << res << "\n";
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