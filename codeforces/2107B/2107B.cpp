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
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;

  ll sm = 0;
  ll mn = INT_MAX;
  ll mx = 0;
  ll cnt = 0;
  for (auto c : a)
  {
    sm += c;
    mx = max(mx, c);
    mn = min(mn, c);
  }

  for (auto c : a)
    if (c == mx)
      cnt++;

  ll carry = 0;
  if (cnt == 1)
    carry++;

  if (mx - carry - mn > k)
  {
    cout << "Jerry" << "\n";
    return;
  }

  if (sm % 2 == 0)
  {
    cout << "Jerry" << "\n";
  }
  else
    cout << "Tom" << "\n";
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