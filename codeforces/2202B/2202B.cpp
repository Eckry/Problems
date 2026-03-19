#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  if (n % 2 == 0) {
    s = 'a' + s;
    n++;
  } else {
    if (s[0] == 'b') {
      cout << "NO\n";
      return;
    }
    s[0] = 'a';
  }

  for (int i = 1; i < n - 1; i += 2) {
    if (s[i] == 'a') {
      if (s[i + 1] == 'a') {
        cout << "NO\n";
        return;
      }
      s[i + 1] = 'b';
    }
    if (s[i] == 'b') {
      if (s[i + 1] == 'b') {
        cout << "NO\n";
        return;
      }
      s[i + 1] = 'a';
    }
  }
  for (int i = 2; i < n; i += 2) {
    if (s[i] == 'a') {
      if (s[i - 1] == 'a') {
        cout << "NO\n";
        return;
      }
      s[i - 1] = 'b';
    }
    if (s[i] == 'b') {
      if (s[i - 1] == 'b') {
        cout << "NO\n";
        return;
      }
      s[i - 1] = 'a';
    }
  }
  // cout << s << "\n";
  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
