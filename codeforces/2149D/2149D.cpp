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
  ll ansA = 0;
  vector<int> b(n, 0);
  vector<int> a(n, 0);
  int cntB = 0;
  int cntA = 0;
  if (s[0] == 'b') {
    b[0]++;
    cntB++;
  }
  if (s[0] == 'a') {
    a[0]++;
    cntA++;
  }

  for (int i = 1; i < n; i++) {
    b[i] = b[i - 1];
    a[i] = a[i - 1];
    if (s[i] == 'b') {
      cntB++;
      b[i]++;
    } else {
      cntA++;
      a[i]++;
    }
  }
  // for(auto c : a) cout << c<< " ";
  // cout << "\n";
  // for(auto c : b) cout << c<< " ";
  // cout << "\n";
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a') {
      if (b[i] < cntB - b[i]) {
        ansA += b[i];
      } else {
        ansA += cntB - b[i];
      }
      // cout << i << " " << ansA << " " << b[i] << "\n";
    }
  }
  // cout << cntB << "\n";
  ll ansB = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'b') {
      if (a[i] < cntA - a[i]) {
        ansB += a[i];
      } else {
        ansB += cntA - a[i];
      }
    }
  }

  // cout << ansA << " " << ansB << "\n";
  cout << min(ansA, ansB) << "\n";
}

int main() {
  optimize() int T;
  cin >> T;
  while (T--)
    solve();
}
