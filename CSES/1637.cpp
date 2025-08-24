#include <bits/stdc++.h>

using namespace std;
vector<int> dp;
int check(int n) {
  if (n == 0)
    return 0;
  if (dp[n] != -1)
    return dp[n];
  vector<int> nums;
  int temp = n;
  while (temp) {
    int nm = temp % 10;
    if (nm != 0 && nm <= n)
      nums.push_back(nm);
    temp /= 10;
  }
  int ans = 10000000;
  for (int i = 0; i < nums.size(); i++) {
    ans = min(ans, 1 + check(n - nums[i]));
  }
  dp[n] = ans;
  return ans;
}

void solve() {
  int n;
  cin >> n;
  dp = vector<int>(n + 1, -1);
  dp[0] = 0;
  int ans = check(n);
  cout << ans << "\n";
}

int main(void) { solve(); }
