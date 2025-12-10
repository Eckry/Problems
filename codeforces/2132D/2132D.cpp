#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll calc(ll n) {
  if (n == 9)
    return 45LL;
  return calc(n / 10LL) * 10LL + 45LL * (n / 10LL + 1LL);
}

ll sm(ll n) {
  if (n <= 9LL) {
    return n * (n + 1LL) / 2LL;
  }

  ll pow = 1LL;
  while (pow * 10LL <= n) {
    pow *= 10LL;
  }
  ll msd = n / pow;
  ll acc = msd * calc(pow - 1LL) + msd * (msd - 1) / 2 * (pow);
  acc += msd * (n % pow + 1LL) + sm(n % pow);
  return acc;
}

void solve() {
  ll k;
  cin >> k;
  if (k <= 9) {
    cout << k * (k + 1) / 2 << "\n";
    return;
  }

  ll cnt = 1;
  ll pow = 9;
  ll num = 0;
  while (true) {
    if (cnt * pow > k)
      break;
    k -= cnt * pow;
    num += pow;
    cnt++;
    pow *= 10LL;
  }
  ll m = k / cnt;
  ll number = num + m;
  ll ans = sm(number);
  ll res = k % cnt;
  string s = to_string(number + 1);
  for (int i = 0; i < res; i++) {
    ans += s[i] - '0';
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
