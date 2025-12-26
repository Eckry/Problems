#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
  int n;
  cin >> n;
  int l = (1LL << n) - 1;
  int cur = l;
  int vit = n - 1;
  vector<int> ans;
  vector<int> used(l + 1, 0);
  for (int i = 0; i <= l; i++) {
    ans.push_back(cur);
    used[cur] = 1;
    // cout << vit << "\n";
    if (vit == -1)
      break;
    if (n - vit - 1 >= 2) {
      int temp = cur;
      int diff = n - vit - 2;
      // cout << diff << " " << vit << " diff\n";
      for (int j = 1; j <= (1LL << (diff)) - 1; j++) {
        int bits = j << (vit + 2);
        ans.push_back(cur | bits);
        used[cur | bits] = 1;
        // cout << "Inserting: " << (cur | bits) << "\n";
      }
    }
    cur ^= (1 << vit);
    vit--;
  }
  for (int i = 0; i <= l; i++) {
    if (!used[i])
      ans.push_back(i);
  }
  for (auto c : ans) {
    cout << c << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve();
}
