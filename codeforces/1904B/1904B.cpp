#include <bits/stdc++.h>

using namespace std;

#define optimize()              \
  cin.tie(0);                   \
  cin.sync_with_stdio(0);       \
  ios_base::sync_with_stdio(0); \
  cout.tie(0);

int compare(const void *a, const void *b)
{
  return (*(int *)a - *(int *)b);
}

void solve()
{
  int n;
  cin >> n;
  long long int numb[n];
  long long int s[n];
  map<long long int, int> ans;
  for (int i = 0; i < n; i++)
  {
    cin >> numb[i];
    s[i] = numb[i];
  }

  qsort(numb, n, sizeof(long long int), compare);

  long long int sum = numb[0];
  int count = 0;
  for (int i = 1; i < n; i++)
  {
    if (sum >= numb[i])
    {
      sum += numb[i];
      count++;
      ans[i - 1] = -1;
    }
    else
    {
      ans[i - 1] = count;
      sum += numb[i];
      count++;
    }
  }
  ans[n - 1] = count;
  map<long long int, long long int> x;
  int p = ans[n - 1];
  for (int i = n - 1; i >= 0; i--)
  {
    if(ans[i] != -1 && p > ans[i]) p = ans[i];
    x[i] = p;
  }
  map<long long int, long long int > ans2;
  for(int i = 0 ; i < n; i++){
    ans2[numb[i]] = x[i];
  }

  for(int i = 0; i < n; i++){
    cout << ans2[s[i]] << " ";
  }

  cout << endl;
}

int main(void)
{
  optimize();
  int T;
  cin >> T;
  //T = 1;
  while (T--)
    solve();
}