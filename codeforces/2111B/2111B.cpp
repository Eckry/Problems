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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> boxes(m, vector<int>(3));
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cin >> boxes[i][j];
    }
  }

  vector<int> fibo(n);
  fibo[0] = 1;
  fibo[1] = 2;
  for (int i = 2; i < n; i++)
  {
    fibo[i] = fibo[i - 1] + fibo[i - 2];
  }
  int largest = fibo[n - 1] + fibo[n - 2];
  int smallest = fibo[n - 1];

  for (int i = 0; i < m; i++)
  {
    sort(boxes[i].begin(), boxes[i].end());
    int lg = boxes[i][2];
    int sm = boxes[i][1];
    if(largest <= lg && sm >= smallest && boxes[i][0] >= smallest){
      cout << "1" << "";
    } else {
      cout << "0" << "";
    }
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