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
  vector<long long int> a(n);
  for (auto &c : a)
    cin >> c;

  if (n == 1)
  {
    if (a[0] > 0)
    {
      cout << 2 << "\n";
      cout << 0 << " ";
      cout << a[0] << "\n";
    }
    else if (a[0] < 0)
    {
      cout << 2 << "\n";
      cout << a[0] << " ";
      cout << 0 << "\n";
    } else {
      cout << 1 << "\n" << 0 << "\n";
    }
    return;
  }

  long long int k = -1;

  for (long long int i = 0; i < n; i++)
  {
    if (a[i] != -1 && a[i] != 1)
    {
      k = i;
      break;
    }
  }

  if (k == -1)
  {
    long long int one = 0;
    long long int minus = 0;
    for (long long int i = 0; i < n; i++)
    {
      if (a[i] == 1)
        one++;
      else
        minus++;
    }

    long long int start = -minus;
    long long int end = one;
    cout << minus + one + 1 << "\n";
    for (long long int i = start; i <= end; i++)
      cout << i << " ";
    cout << "\n";
    return;
  }

  long long int mxl = INT_MIN;
  long long int mnl = INT_MAX;
  long long int mxr = INT_MIN;
  long long int mnr = INT_MAX;

  long long int cur = 0;
  long long int mncur = 0;

  for (long long int i = 0; i < k; i++)
  {
    cur = max(a[i], cur + a[i]);
    mncur = min(a[i], mncur + a[i]);
    mxl = max(mxl, cur);
    mnl = min(mnl, mncur);
  }

  cur = 0;
  mncur = 0;

  for (long long int i = k + 1; i < n; i++)
  {
    cur = max(a[i], cur + a[i]);
    mncur = min(a[i], mncur + a[i]);
    mxr = max(mxr, cur);
    mnr = min(mnr, mncur);
  }

  long long int kmxr = INT_MIN;
  long long int kmnr = INT_MAX;
  long long int sum = 0;
  for (long long int i = k + 1; i < n; i++)
  {
    sum += a[i];
    kmxr = max(kmxr, sum);
    kmnr = min(kmnr, sum);
  }

  long long int kmxl = INT_MIN;
  long long int kmnl = INT_MAX;
  sum = 0;

  for (long long int i = k - 1; i >= 0; i--)
  {
    sum += a[i];
    kmxl = max(kmxl, sum);
    kmnl = min(kmnl, sum);
  }

  set<long long int> ans;

  if (a[k] < 0)
  {
    long long int temp = max(kmxl, kmxr);
    long long int end = max(temp, kmxl + kmxr);
    temp = min(kmnl, kmnr);
    long long int start = min(temp, kmnr + kmnl);
    if (start > 0)
      ans.insert(a[k]);
    for (long long int i = start; i <= end; i++)
    {
      ans.insert(i + a[k]);
    }
    if (end < 0)
      ans.insert(a[k]);
  }

  long long int startx = min(mnl, mnr);
  long long int endx = max(mxl, mxr);

  for (long long int i = min(startx, 0LL); i <= max(endx, 0LL); i++)
  {
    ans.insert(i);
  }

  if (a[k] > 0)
  {
    long long int temp = max(kmxl, kmxr);
    long long int end = max(temp, kmxl + kmxr);
    temp = min(kmnl, kmnr);
    long long int start = min(temp, kmnr + kmnl);
    if (start > 0)
      ans.insert(a[k]);
    for (long long int i = start; i <= end; i++)
    {
      ans.insert(i + a[k]);
    }
    if (end < 0)
      ans.insert(a[k]);
  }

  cout << ans.size() << "\n";
  for (auto c : ans)
    cout << c << " ";

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