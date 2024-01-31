#include <bits/stdc++.h>

using namespace std;

int solve(){
  int n;
  cin >> n;
  if(n % 2 != 0) return 0;
  int x = n / 2;
  return pow(2, x);
}

int main(void){
  cout << solve();
}