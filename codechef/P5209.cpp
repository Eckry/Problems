#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int pureone = 1;
  int purezero = 1;
  int leftone = 0;
  int rightone = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0')
      pureone = 0;
    if (s[i] == '1')
      purezero = 0;
    if (i < n - 1 && s[i] == '0' && s[i + 1] == '1') {
      leftone++;
    }
    if (i < n - 1 && s[i] == '1' && s[i + 1] == '0') {
      rightone++;
    }
  }
  if (pureone || purezero || !leftone || !rightone) {
    cout << "Bob" << "\n";
    return;
  }

  if (leftone == 1 && rightone == 1) {
    cout << "Alice" << "\n";
    return;
  }
  cout << "Alice" << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
