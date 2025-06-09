#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &c : a)
    cin >> c;
  int ans = 0;
  set<int> st;
  set<int> carry;
  st.insert(a[0]);
  for (int i = 1; i < n; i++)
  {
    carry.insert(a[i]);
    if (st.find(a[i]) != st.end())
    {
      st.erase(a[i]);
    }

    if(st.empty()) {
      ans++;
      st = carry;
      carry.clear();
    }
  }
  cout << ans + 1 << "\n";
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