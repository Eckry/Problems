#include <iostream>

using namespace std;
int main()
{
  int T;
  int n;
  cin >> T;
  for (int _ = 0; _ < T; _++)
  {
    cin >> n;
    int a = 1;
    for(int i = 2; i * i <= n; i++){
      if(n % i == 0){
        a = n / i;
        break;
      }
    }
    cout << a << " " << n - a << endl;
  }
  return 0;
}