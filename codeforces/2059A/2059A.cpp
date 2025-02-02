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

  ll cnta = 0;
  ll cntb = 0;
  map<ll, ll> mpa;
  map<ll, ll> mpb;

  for (int i = 1; i < n; i++)
  {
    if (!mpa.count(a[i]))
    {
      cnta++;
      mpa[a[i]++];
    }
  }
  for (int i = 1; i < n; i++)
  {
    if (!mpb.count(b[i]))
    {
      cntb++;
      mpb[b[i]++];
    }
  }
  if (cnta == 2 && cntb == 2)
  {
    cout << "YES" << "\n";
  }
  else if (cnta > 2 || cntb > 2)
  {
    cout << "YES" << "\n";
  }
  else
  {
    cout << "NO" << "\n";
  }
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