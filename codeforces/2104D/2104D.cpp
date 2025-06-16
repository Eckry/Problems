#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);
 
vector<bool> criba(10000000 + 1, 1);
vector<ll> primes;
 
void generate()
{
  criba[0] = 0;
  criba[1] = 0;
  for (int i = 2; i <= 10000000; i++)
  {
    if (criba[i] == 0)
      continue;
    primes.push_back(i);
    for (int j = i * 2; j <= 10000000; j += i)
    {
      criba[j] = 0;
    }
  }
}
 
void solve()
{
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;
  if (n == 1)
  {
    cout << 0 << "\n";
    return;
  }
 
  ll sm = 0;
  ll smprimes = 0;
  ll ans = n;
  sort(a.begin(), a.end(), greater<>());
  for (int i = 0; i < n; i++)
  {
    sm += a[i];
    smprimes += primes[i];
    if (sm >= smprimes)
      ans--;
  }
  cout << ans << "\n";
}
 
int main(void)
{
  generate();
  optimize();
  int T;
  cin >> T;
  // T = 1;
  while (T--)
    solve();
}