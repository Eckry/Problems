#include <bits/stdc++.h>

using namespace std;

#define ll long long

int sol(int x, string &s, vector<int> &idx, char up, char down, char p,
        char n) {
  int oneup = -1;
  int onedown = -1;
  for (auto i : idx) {
    char c = s[i];
    if (c == up) {
      oneup = i;
      x++;
    } else {
      onedown = i;
      x--;
    }
  }
  if (oneup == -1 && onedown == -1)
    return 1;
  if (x == 0) {
    s[onedown] = p;
    s[oneup] = p;
    for (auto i : idx) {
      if (i == onedown || i == oneup) {
        continue;
      }
      s[i] = n;
    }
    return 1;
  } else {
    int px = 0;
    int N = 1;
    if (x < 0) {
      x = -x;
      N = 0;
    }
    while (x > px) {
      x--;
      px++;
    }
    if (x != px)
      return 0;
    for (auto i : idx) {
      if (N) {
        if (px && s[i] == up) {
          px--;
          s[i] = p;
        } else {
          s[i] = n;
        }
      } else {
        if (px && s[i] == down) {
          px--;
          s[i] = p;
        } else {
          s[i] = n;
        }
      }
    }

    int h = 0;
    int r = 0;
    for (auto i : idx) {
      if (s[i] == p)
        h++;
      if (s[i] == n)
        r++;
    }
    if (!r || !h) {
      return 0;
    }
    return 1;
  }
}

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  if (n == 2 && s[0] != s[1]) {
    cout << "NO\n";
    return;
  }
  vector<int> N;
  vector<int> E;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'N' || s[i] == 'S') {
      N.push_back(i);
    } else {
      E.push_back(i);
    }
  }
  int x = sol(0, s, E, 'E', 'W', 'R', 'H');
  int y = sol(0, s, N, 'N', 'S', 'H', 'R');
  if (!x || !y) {
    cout << "NO\n";
  } else {
    cout << s << "\n";
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
