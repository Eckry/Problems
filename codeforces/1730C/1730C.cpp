#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  string s;
  cin >> s;
  string cop = s;
  int n = s.size();

  stack<int> st;
  st.push(0);
  for (int i = 1; i < n; i++)
  {
    while (!st.empty() && s[st.top()] > s[i])
      st.pop();

    st.push(i);
  }
  string ans = "";

  for (int i = n - 1; i >= 0; i--)
  {
    if (!st.empty() && i == st.top())
    {
      ans += s[i];
      st.pop();
    }
    else
    {
      if (s[i] == '9')
      {
        ans += '9';
      }
      else
        ans += s[i] + 1;
    }
  }

  sort(ans.begin(), ans.end());
  cout << ans << "\n";
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