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
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll> a(n);
    for (auto &c : a)
        cin >> c;
    ll sm = -1000001;
    ll mxsm = -1000001;
    vector<ll> mx;

    if (n == 1)
    {
        if (s[0] == '0' || a[0] == k)
        {
            cout << "YES" << "\n";
            cout << k << "\n";
            return;
        }
        else
        {
            cout << "NO" << "\n";
            return;
        }
    }
    int flg = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            flg = 1;
            sm = max(sm + a[i], a[i]);
            mxsm = max(mxsm, sm);
        }
        if (s[i] == '0' && flg)
        {
            flg = 0;
            mx.push_back(mxsm);
            sm = -1000001;
            mxsm = -1000001;
        }
    }
    if (flg)
    {
        mx.push_back(mxsm);
    }
    flg = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            flg = 1;
    }
    if (!flg)
    {
        if (mxsm == k)
        {
            cout << "YES" << "\n";
            for (int i = 0; i < n; i++)
            {
                cout << a[i] << " ";
            }
            cout << "\n";
            return;
        }
        else
        {
            cout << "NO" << "\n";
            return;
        }
    }
    ll smmx = -1000001;
    for (auto c : mx)
    {
        smmx = max(c, smmx);
        if (smmx > k)
        {
            cout << "NO" << "\n";
            return;
        }
    }

    int j = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        j = i;
        if (s[i] == '0')
            cnt++;
        if (cnt == 2)
            break;
    }
    if (s[j] == '0' && cnt == 2)
        j--;
    ll l = -1000000000000000000LL;
    ll r = 1000000000000000000LL;
    while (l <= r)
    {
        ll m = l + (r - l) / 2;
        ll smmx = -1000000000000000000LL;
        ll sm = -1000000000000000000LL;
        for (int i = 0; i <= j; i++)
        {
            if (s[i] == '0')
            {
                sm = max(sm + m, m);
                smmx = max(sm, smmx);
                continue;
            }
            sm = max(sm + a[i], a[i]);
            smmx = max(sm, smmx);
        }

        if (smmx > k)
        {
            r = m - 1;
        }
        else if (smmx < k)
        {
            l = m + 1;
        }
        else
        {
            cout << "YES" << "\n";
            for (int i = 0; i <= j; i++)
            {
                if (s[i] == '0')
                {
                    cout << m << " ";
                    continue;
                }
                cout << a[i] << " ";
            }
            for (int i = j + 1; i < n; i++)
            {
                if (s[i] == '0')
                    cout << -1000000000000000000LL << " ";
                else
                    cout << a[i] << " ";
            }
            cout << "\n";
            return;
        }
    }
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