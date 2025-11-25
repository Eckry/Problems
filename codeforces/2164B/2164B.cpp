#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<int> primes;
vector<vector<int>> sieve(10000, vector<int>());
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;
  if (a[0] == 1) {
    cout << a[0] << " " << a[1] << "\n";
    return;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if ((a[i] % a[j]) % 2 == 0) {
        cout << a[j] << " " << a[i] << "\n";
        return;
      }
    }
  }
  cout << -1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  for (int i = 2; i < 10000; i++) {
    if (!sieve[i].empty())
      continue;
    primes.push_back(i);
    for (int j = i; j < 10000; j += i) {
      sieve[j].push_back(i);
    }
  }
  int T;
  cin >> T;
  while (T--)
    solve();
}
