#include <bits/stdc++.h>

using namespace std;

int solve()
{
  int x, n;
  cin >> x >> n;
  int r = 1;
  for(int i = 1; i * i <= x; i++){
    if(x % i == 0){
      if(n <= x / i) r = max(r, i);
      if(n <= i) r = max(r, x / i);
    }
  }
  return r;
};

int main(void)
{
  int T;
  cin >> T;
  while (T--)
  {
    cout << solve() << endl;
  }
}