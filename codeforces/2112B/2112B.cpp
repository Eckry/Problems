#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define optimize()                \
    cin.tie(0);                   \
    cin.sync_with_stdio(0);       \
    ios_base::sync_with_stdio(0); \
    cout.tie(0);

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &c : a)
        cin >> c;
    for (int i = 0; i < n - 1; i++)
    {
        if (abs(a[i] - a[i + 1]) <= 1)
        {
            cout << 0 << " \n";
            return;
        }
    }

    int inc = 1;
    int dec = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] < a[i + 1])
        {
            dec = 0;
        }
        if (a[i] > a[i + 1])
        {
            inc = 0;
        }
    }
    if (inc || dec)
    {
        cout << -1 << " \n";
        return;
    }
    cout << 1 << " \n";
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