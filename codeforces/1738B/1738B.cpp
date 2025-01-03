#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<long long int> s(k);
  for (auto &c : s)
    cin >> c;

  if(k == 1) {
    cout << "YES" << "\n";
    return;
  }

  vector<long long int> ans;
  long long int prev = s[0];
  for (int i = 1; i < k; i++)
  {
    ans.push_back(s[i] - prev);
    prev = s[i];
  }

  if (!is_sorted(ans.begin(), ans.end()))
  {
    cout << "NO" << "\n";
    return;
  }

  if(s[0] > (n - k + 1) * ans[0]){
    cout << "NO" << "\n";
    return;
  }

  cout << "YES" << "\n";
}

int main(void)
{
  optimize();
  int T;
  cin >> T;
  // T = 1;
  while (T--)
    solve();
}