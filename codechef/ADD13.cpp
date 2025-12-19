#include <bits/stdc++.h>
#include <pthread.h>

using namespace std;

#define ll long long

void solve() {
  ll n, m;
  cin >> n >> m;

  if (n > m) {
    cout << "NO\n";
    return;
  }

  ll threes = m / 3;
  ll ones = m % 3;
  n -= threes + ones;
  if (!n) {
    cout << "YES\n";
  } else {
    if (n < 0) {
      cout << "NO\n";
      return;
    }
    if (n & 1) {
      cout << "NO\n";
      return;
    }

    cout << "YES\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
