#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n;
  cin >> n;
  long long int totalSize = 0;
  vector<set<int>> S(n);
  set<int> total;
  for (int i = 0; i < n; i++)
  {
    int k;
    cin >> k;
    set<int> temp;
    S[i] = temp;
    for (int j = 0; j < k; j++)
    {
      int x;
      cin >> x;
      total.insert(x);
      S[i].insert(x);
    }
  }

  long long int ans = 0;
  for (int i = 1; i <= 50; i++)
  {
    set<int> st;
    for (int j = 0; j < n; j++)
    {
      if (S[j].count(i) == 0)
      {
        for (auto c : S[j])
        {
          st.insert(c);
        }
      }
    }
    if (ans < st.size() && total.size() > st.size())
      ans = st.size();
  }

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