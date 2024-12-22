#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n, q;
  cin >> n >> q;
  vector<long long int> a(n);
  for (auto &c : a)
    cin >> c;

  vector<long long int> sum(n + 1);
  sum[0] = a[0];
  for (int i = 1; i < n; i++)
  {
    sum[i] = sum[i - 1] + a[i];
  }

  vector<long long int> ans = {sum[0]};
  map<long long int, long long int> m;
  long long int j = 0;
  for (int i = 0; i < n; i++)
  {
    if (j < a[i])
      j = a[i];
    m[j] = sum[i];
    if (ans[ans.size() - 1] != j)
      ans.push_back(j);
  }

  for (int i = 0; i < q; i++)
  {
    long long int k;
    cin >> k;
    if (k < ans[0])
    {
      cout << 0 << " ";
      continue;
    }

    int l = 0;
    int r = ans.size() - 1;
    while (l != r)
    {
      int mid = (l + r + 1) / 2;
      if (ans[mid] < k)
      {
        l = mid;
      }
      else if (ans[mid] > k)
      {
        r = mid - 1; // 1 3 4 5 6
      }
      else
      {
        r = mid;
        break;
      }
    }

    if (ans[r] > k)
      r--;

    cout << m[ans[r]] << " ";
  }

  cout << "\n";
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