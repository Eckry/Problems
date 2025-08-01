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
    ll n, c;
    cin >> n >> c;
    vector<ll> a(n);
    for (auto &d : a)
        cin >> d;

    ll ans = 0;
    ll j = 0;
    sort(a.begin(), a.end(), greater<>());
    for (int i = 0; i < n; i++)
    {
        if(a[i] * (1LL << j) <= c){
            j++;
            ans++;
        }
    }
    cout << n - ans << "\n";
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