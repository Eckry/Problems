#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

void solve()
{
  int n, l, r;
  cin >> n >> l >> r;

  vector<long long> a(n);
  for (auto &c : a)
    cin >> c;

  vector<long long> left;
  vector<long long> right;
  vector<long long> mid;

  for (int i = 0; i < l - 1; i++)
    left.push_back(a[i]);
  for (int i = r; i < n; i++)
    right.push_back(a[i]);
  for (int i = l - 1; i < r; i++)
    mid.push_back(a[i]);
  sort(left.begin(), left.end());
  sort(right.begin(), right.end());
  sort(mid.begin(), mid.end(), greater<>());

  long long ans = 0;
  int j = 0;
  long long sm = 0;
  vector<long long> temp = mid;
  for (int i = 0; i < right.size(); i++)
  {
    if (right[i] < temp[j])
    {
      temp[j] = right[i];
      j++;
      if (j == temp.size())
        break;
    }
  }
  for (auto c : temp)
    sm += c;

  ans = sm;
  temp = mid;
  sm = 0;
  j = 0;
  for (int i = 0; i < left.size(); i++)
  {
    if (left[i] < temp[j])
    {
      temp[j] = left[i];
      j++;
      if (j == temp.size())
        break;
    }
  }
  for (auto c : temp)
    sm += c;
  ans = min(sm, ans);
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