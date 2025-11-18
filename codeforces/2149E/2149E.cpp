#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n, k, l, r;
  cin >> n >> k >> l >> r;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;

  set<int> stright;
  set<int> ststart;
  map<int, int> mpright;
  map<int, int> mpstart;
  int left = 0;
  int right = -1;
  int start = -1;
  ll ans = 0;
  while (left < n) {
    while (start < n && ststart.size() < k) {
      start++;
      ststart.insert(a[start]);
      mpstart[a[start]]++;
    }
    while (right < n && stright.size() <= k) {
      right++;
      stright.insert(a[right]);
      mpright[a[right]]++;
    }

    ans += max(0, min(right - 1, left + r - 1) - max(start, left + l - 1) + 1);
    mpright[a[left]]--;
    mpstart[a[left]]--;
    if (!mpright[a[left]]) {
      stright.erase(stright.find(a[left]));
    }
    if (!mpstart[a[left]]) {
      ststart.erase(ststart.find(a[left]));
    }
    left++;
  }

  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
