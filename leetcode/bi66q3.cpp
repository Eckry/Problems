#include <bits/stdc++.h>

using namespace std;

#define ll long long

int distinctPoints(string s, int k) {
  map<pair<int, int>, int> mp;
  pair<int, int> pos = {0, 0};
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == 'U') {
      pos.second++;
    }
    if (s[i] == 'D') {
      pos.second--;
    }
    if (s[i] == 'L') {
      pos.first--;
    }
    if (s[i] == 'R') {
      pos.first++;
    }
  }
  for (int i = 0; i < k; i++) {
    if (s[i] == 'U') {
      pos.second--;
    }
    if (s[i] == 'D') {
      pos.second++;
    }
    if (s[i] == 'L') {
      pos.first++;
    }
    if (s[i] == 'R') {
      pos.first--;
    }
  }

  mp[pos]++;
  int cnt = 1;
  for (int i = k; i < n; i++) {
    if (s[i - k] == 'U') {
      pos.second++;
    }
    if (s[i - k] == 'D') {
      pos.second--;
    }
    if (s[i - k] == 'L') {
      pos.first--;
    }
    if (s[i - k] == 'R') {
      pos.first++;
    }
    if (s[i] == 'U') {
      pos.second--;
    }
    if (s[i] == 'D') {
      pos.second++;
    }
    if (s[i] == 'L') {
      pos.first++;
    }
    if (s[i] == 'R') {
      pos.first--;
    }
    if (!mp.count(pos)) {
      mp[pos]++;
      cnt++;
    }
  }
  return cnt;
}
