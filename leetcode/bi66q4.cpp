#include <bits/stdc++.h>

using namespace std;

#define ll long long

void dfs(int u, int p, vector<int> &visited, vector<vector<int>> &adj,
         vector<int> &numbers, int &cnteven, vector<int> &nums) {
  if (visited[u])
    return;
  visited[u] = 1;
  cout << u << "\n";
  if (u % 2 == 0) {
    cnteven++;
  }
  numbers.push_back(nums[u]);
  for (auto v : adj[u]) {
    if (v == p)
      continue;
    dfs(v, u, visited, adj, numbers, cnteven, nums);
  }
}
long long maxAlternatingSum(vector<int> &nums, vector<vector<int>> &swaps) {
  int n = nums.size();
  int m = swaps.size();
  vector<vector<int>> adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x = swaps[i][0];
    int y = swaps[i][1];
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  vector<int> visited(n, 0);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (visited[i])
      continue;
    cout << "xd";
    vector<int> numbers;
    int cnteven = 0;
    dfs(i, -1, visited, adj, numbers, cnteven, nums);
    sort(numbers.rbegin(), numbers.rend());
    for (int i = 0; i < numbers.size(); i++) {
      if (cnteven) {
        ans += numbers[i];
        cnteven--;
      } else {
        ans -= numbers[i];
      }
    }
  }
  return ans;
}
