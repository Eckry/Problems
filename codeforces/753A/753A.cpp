#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  int n;
  cin >> n;
  vector<int> kids;
  int sum = 0;
  int counter = 0;
  for (int i = 1; i < n; i++)
  {
    if (sum > n)
      break;
    sum += i;
    counter++;
    kids.push_back(i);
  }

  if (sum > n)
  {
    int x = sum - n;
    for (int i = 0; i < n; i++)
    {
      if (kids[i] == x)
      {
        counter--;
        kids[i] = 0;
        break;
      }
    }
  }

  if (counter == 1 || counter == 0)
  {
    cout << 1 << endl;
    cout << n;
  }
  else
  {
    cout << counter << endl;
    for (int i = 0; i < kids.size(); i++)
    {
      if (kids[i] == 0)
        continue;
      cout << kids[i] << " ";
    }
  }
}