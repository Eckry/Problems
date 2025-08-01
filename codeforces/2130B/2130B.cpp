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
    int s;
    cin >> s;

    vector<int> a(n);
    for (auto &c : a)
        cin >> c;

    int sm = 0;
    int ones = 0;
    int zeros = 0;
    int twos = 0;
    for (auto c : a)
    {
        if (c == 1)
            ones++;
        if (c == 0)
            zeros++;
        if (c == 2)
            twos++;
        sm += c;
    }

    if (sm > s || s - (sm - 3) == 4)
    {
        for (int i = 0; i < zeros; i++)
        {
            cout << 0 << " ";
        }
        for (int i = 0; i < twos; i++)
        {
            cout << 2 << " ";
        }
        for (int i = 0; i < ones; i++)
        {
            cout << 1 << " ";
        }
        cout << "\n";
        return;
    }
    cout << -1 << "\n";
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