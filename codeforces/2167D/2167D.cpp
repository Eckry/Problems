#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<ll> primes;
vector<int> sieve(1000001, 1);

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &c : a)
    cin >> c;

  ll best = primes[primes.size() - 1];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < primes.size(); j++) {
      if (primes[j] >= best)
        break;
      if (a[i] % primes[j]) {
        best = min(best, primes[j]);
        break;
      }
    }
  }
  cout << best << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  for (int i = 2; i <= 1000000; i++) {
    if (!sieve[i])
      continue;
    primes.push_back(i);
    for (int j = i * 2; j <= 1000000; j += i) {
      sieve[j] = 0;
    }
  }
  int T;
  cin >> T;
  while (T--)
    solve();
}
