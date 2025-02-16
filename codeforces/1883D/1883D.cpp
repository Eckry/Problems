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
  int q;
  cin >> q;
  multiset<ll> right;
  multiset<ll> left;
  while (q--)
  {
    char op;
    cin >> op;
    ll l, r;
    cin >> l >> r;
    if (op == '+')
    {
      right.insert(r);
      left.insert(l);
      auto mnL = left.rbegin();
      auto mnR = right.begin();
      if (*mnR < *mnL)
      {
        cout << "YES" << "\n";
      }
      else
      {
        cout << "NO" << "\n";
      }
    }
    else
    {
      right.erase(right.find(r));
      left.erase(left.find(l));
      if(left.empty()){
        cout << "NO" << "\n";
        continue;
      }
      auto mnL = left.rbegin();
      auto mnR = right.begin();
      if (*mnR < *mnL)
      {
        cout << "YES" << "\n";
      }
      else
      {
        cout << "NO" << "\n";
      }
    }
  }
}

int main(void)
{
  optimize();
  int T;
  // cin >> T;
  T = 1;
  while (T--)
    solve();
}