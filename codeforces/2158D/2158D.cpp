#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<pair<int, int>> con(string s) {
  vector<pair<int, int>> ans;
  int n = s.size();
  int i = -1, j = -1;
  int bit = 0;
  for (int l = 0; l < n - 1; l++) {
    if (s[l] == s[l + 1]) {
      i = l;
      j = l + 1;
      bit = s[i] - '0';
      break;
    }
  }
  if (i == -1) {
    for (int i = 1; i < n - 1; i++) {
      if (s[i - 1] != s[i] && s[i] != s[i + 1]) {
        for (int j = i - 1; j <= i + 1; j++) {
          if (s[j] == '1')
            s[j] = '0';
          else
            s[j] = '1';
        }
        ans.push_back({i - 1, i + 1});
        break;
      }
    }
    for (int l = 0; l < n - 1; l++) {
      if (s[l] == s[l + 1]) {
        i = l;
        j = l + 1;
        bit = s[i] - '0';
        break;
      }
    }
  }

  if (i != -1) {
    while (i != -1 || j != n) {
      while (i >= 0 && s[i] - '0' == bit)
        i--;
      while (j < n && s[j] - '0' == bit)
        j++;
      if (j == n && i == -1)
        break;
      ans.push_back({i + 1, j - 1});
      bit = 1 - bit;
    }
  }
  if (bit) {
    ans.push_back({0, n - 1});
  }
  return ans;
}

void solve() {
  int n;
  cin >> n;
  string s;
  string t;
  cin >> s >> t;
  vector<pair<int, int>> sop = con(s);
  vector<pair<int, int>> top = con(t);

  cout << sop.size() + top.size() << "\n";
  for (auto [l, r] : sop) {
    cout << l + 1 << " " << r + 1 << "\n";
  }
  for (int i = (int)top.size() - 1; i >= 0; i--) {
    cout << top[i].first + 1 << " " << top[i].second + 1 << "\n";
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
