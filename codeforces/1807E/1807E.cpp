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
  scanf("%d", &n);
  vector<ll> a(n);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  vector<ll> sm(n + 1);
  sm[0] = 0;
  for (int i = 1; i <= n; i++)
    sm[i] = sm[i - 1] + a[i - 1];
  ll l = 1;
  ll r = n;
  ll ans = 0;
  while (l <= r)
  {
    ll mid = (l + r) / 2;
    printf("? %d ", mid - l + 1);
    for (ll i = l; i <= mid; i++)
      printf("%d ", i);
    printf("\n");
    fflush(stdout);
    ll x;
    scanf("%d", &x);
    if (x == sm[mid] - sm[l - 1])
    {
      l = mid + 1;
    }
    else
    {
      r = mid - 1;
      ans = mid;
    }
  }
  printf("! %d\n", ans);
  fflush(stdout);
}

int main(void)
{
  optimize();
  int T;
  scanf("%d", &T);
  // T = 1;
  while (T--)
    solve();
}