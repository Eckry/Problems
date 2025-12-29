#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int two = 0;
  int one = 100000;
  for (int i = 0; i < n - 3; i++) {
    int cnt = 0;
    if (s[i] == '2')
      cnt++;
    if (s[i + 1] == '0')
      cnt++;
    if (s[i + 2] == '2')
      cnt++;
    if (s[i + 3] == '6')
      cnt++;
    if (s[i] == '2' && s[i + 1] == '0' && s[i + 2] == '2' && s[i + 3] == '5') {
      two++;
    }
    one = min(one, 4 - cnt);
  }
  // cout << one << "xd\n";
  cout << min(two, one) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
