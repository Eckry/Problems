#include <bits/stdc++.h>

using namespace std;

vector<string> solve(vector<string> &words, int maxWidth) {
  int cnt = 0;
  vector<string> ans;
  string s = "";
  int n = words.size();
  int last = 0;
  for (int i = 0; i < n; i++) {
    cnt += words[i].size() + 1;
    // cout << cnt << "\n";
    if (cnt > maxWidth + 1) {
      cnt -= words[i].size() + 1;
      int diff = maxWidth - cnt + 1;
      int numofspaces = i - last - 1;
      if (numofspaces == 0) {
        s += words[last];
        while (s.size() < maxWidth) {
          s += ' ';
        }
      } else {
        int iterate = diff / numofspaces;
        int res = diff % numofspaces;
        for (int j = last; j < i - 1; j++) {
          s += words[j] + ' ';
          // cout << i << " ";
          // cout << diff << " " << numofspaces << " " << iterate << " " << res
          //      << "\n";
          if (j - last < res) {
            s += ' ';
          }
          for (int k = 0; k < iterate; k++) {
            s += ' ';
          }
        }
        s += words[i - 1];
      }

      last = i;
      cnt = 0;
      ans.push_back(s);
      s = "";
      i--;
    }
  }
  for (int i = last; i < n - 1; i++) {
    s += words[i] + ' ';
  }
  s += words[n - 1];

  while (s.size() < maxWidth) {
    s += ' ';
  }
  ans.push_back(s);

  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &c : a)
      cin >> c;
    int maxWidth;
    cin >> maxWidth;
    vector<string> ans = solve(a, maxWidth);
    for (auto c : ans) {
      cout << c << "\n";
    }
    cout << "\n";
  }

  return 0;
}
