#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                                                             \
  cin.tie(0);                                                                  \
  cin.sync_with_stdio(0);                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cout.tie(0);

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 2; i < n - 2; i++) {
    if (s[i - 2] == '1' && s[i - 1] == '1' && s[i] == '0' && s[i + 1] == '1' &&
        s[i + 2] == '1') {
      cout << "NO" << "\n";
      return;
    }
  }
  vector<char> lol;
  int zeros = 0;
  int ones = 0;
  char prev = s[0];
  if (prev == '1')
    ones++;
  if (prev == '0')
    zeros++;
  for (int i = 1; i < n; i++) {
    if (prev != s[i]) {
      if (ones > 1) {
        lol.push_back('x');
      } else if (ones == 1) {
        lol.push_back('1');
      }
      if (zeros > 1) {
        lol.push_back('2');
      } else if (zeros == 1) {
        lol.push_back('0');
      }
      ones = 0;
      zeros = 0;
    }

    prev = s[i];
    if (prev == '1')
      ones++;
    if (prev == '0')
      zeros++;
  }
  if (ones > 1) {
    lol.push_back('x');
  } else if (ones == 1) {
    lol.push_back('1');
  }
  if (zeros > 1) {
    lol.push_back('2');
  } else if (zeros == 1) {
    lol.push_back('0');
  }
  if (lol[0] == '0')
    lol[0] = '2';
  if (lol[lol.size() - 1] == '0')
    lol[lol.size() - 1] = '2';

  zeros = 0;
  int twos = 0;

  // for (auto c : lol)
  //   cout << c << " ";
  // cout << "\n";
  for (int i = 0; i < lol.size(); i++) {
    if (lol[i] == '2')
      twos++;
    if (lol[i] == '0')
      zeros++;

    if (lol[i] == 'x') {
      if (twos >= 1) {
        twos = 0;
        zeros = 0;
        continue;
      }
      if (zeros % 2 == 0) {
        twos = 0;
        zeros = 0;
        continue;
      }
      cout << "NO" << "\n";
      return;
    }
  }
  if (twos == 0 && zeros & 1) {
    cout << "NO" << "\n";
    return;
  }

  cout << "YES" << "\n";
}

int main() {
  optimize();
  int T;
  cin >> T;
  while (T--)
    solve();
}
