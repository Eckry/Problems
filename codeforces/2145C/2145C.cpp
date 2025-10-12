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

  vector<int> qnt;

  int sm = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a') {
      qnt.push_back(1);
      sm++;
    } else {
      qnt.push_back(-1);
      sm--;
    }
  }

  // cout << sm << " sm\n";
  // for (auto c : qnt)
  //   cout << c << " ";
  // cout << "\n";

  if (sm == 0) {
    cout << 0 << "\n";
    return;
  }

  if (sm == n || sm == -n) {
    cout << -1 << "\n";
    return;
  }

  map<int, int> prefixIndex;
  int prefixSum = 0;
  int minLength = INT_MAX;
  prefixIndex[0] = -1;
  for (int i = 0; i < qnt.size(); i++) {
    prefixSum += qnt[i];

    int needed = prefixSum - sm;
    if (prefixIndex.count(needed)) {
      int length = i - prefixIndex[needed];
      minLength = min(minLength, length);
    }

    prefixIndex[prefixSum] = i;
  }
  // cout << minLength << "\n";
  if (minLength == n || minLength == INT_MAX)
    cout << -1 << "\n";
  else
    cout << minLength << "\n";
}

int main() {
  optimize() int T;
  cin >> T;
  while (T--)
    solve();
}
