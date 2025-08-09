#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                                                             \
  cin.tie(0);                                                                  \
  cin.sync_with_stdio(0);                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cout.tie(0);

vector<bool> eratosthenes(10000001, 1);
vector<ll> primes;

void createPrimes() {
  for (int i = 2; i <= 10000000; i++) {
    if (!eratosthenes[i])
      continue;
    primes.push_back(i);
    for (int j = i; j <= 10000000; j += i) {
      eratosthenes[j] = 0;
    }
  }
}

void solve() {
  ll n;
  cin >> n;
  ll k = primes.size() - 1;
  ll l = 0;
  ll i = 1;
  ll ans = 0;
  while (k >= 0) {
    while (primes[k] * i > n) {
      k--;
    }
    if (k < 0)
      break;
    i++;
    ans += k + 1;
  }
  cout << ans << "\n";
}

int main() {
  int T;
  cin >> T;
  createPrimes();
  while (T--)
    solve();
}
