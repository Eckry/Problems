#include <bits/stdc++.h>

using namespace std;

#define ll long long

string majorityFrequencyGroup(string s) {
  vector<int> cnt(26, 0);
  int n = s.size();
  vector<int> repeat(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cnt[s[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    if (cnt[i]) {
      repeat[cnt[i]]++;
    }
  }
  int mx = 0;
  for (int i = 0; i <= n; i++) {
    cout << repeat[i] << " ";
    if (repeat[i] >= repeat[mx]) {
      mx = i;
    }
  }
  string letters = "abcdefghijklmnopqrstuvwxyz";
  string ans = "";
  for (int i = 0; i < 26; i++) {
    if (cnt[i] == mx) {
      ans += letters[i];
    }
  }
  return ans;
}
