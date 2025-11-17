#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;

  sort(a.begin(), a.end());

  set<int> st(a.begin(), a.end());
  a = vector<int>(st.begin(), st.end());
  if (a[0] != 1) {
    cout << "Alicius";
    return;
  }

  int winner = 0;
  for (int i = 0; i < n - 1; i++) {
    if (a[i + 1] - a[i] == 1) {
      winner = 1 - winner;
    } else {
      break;
    }
  }
  if (winner)
    cout << "Alicius" << "\n";
  else
    cout << "Bobius" << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  T = 1;
  while (T--)
    solve();
}
