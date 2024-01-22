#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  int n;
  cin >> n;
  int paper[n];
  int ones = 0;
  int best = -100, sum = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> paper[i];
    if (paper[i])
    {
      paper[i] = -1;
      ones++;
    }
    else
      paper[i] = 1;

    sum = max(paper[i], sum + paper[i]);
    best = max(sum, best);
  }

  cout << best + ones;
}