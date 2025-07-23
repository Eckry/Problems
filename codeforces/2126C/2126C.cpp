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
    int n, k;
    cin >> n >> k;
    vector<ll> h(n);
    for (auto &c : h)
        cin >> c;

    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int a, int b)
         { return h[a] < h[b]; });

    k--;
    int i = 0;
    int water = 1;
    int pos = h[k];
    for (; k != idx[i]; i++)
        ;
    while (i < n - 1 && water <= pos)
    {
        water += abs(h[idx[i]] - h[idx[i + 1]]);
        if(water - 1 > pos) break;
        pos = h[idx[i + 1]];
        i++;
    }
    if (pos >= water)
    {
        cout << "YES" << "\n";
    }
    else
        cout << "NO" << "\n";
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