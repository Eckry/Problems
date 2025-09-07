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
    vector<ll> a(n);
    for (auto &c : a)
        cin >> c;

    vector<int> seen(n + 1, 0);
    vector<ll> ans;
    sort(a.begin(), a.end());
    ll mex = 0;
    for (int i = 0; i < n; i++)
    {
        seen[a[i]]++;
        while (seen[mex])
            mex++;
    }

    for (int i = 0; i < n; i++)
    {
        if (seen[a[i]] > 1)
        {
            ans.push_back(mex);
        }
        else
        {
            ans.push_back(min(a[i], mex));
        }
    }
    sort(ans.begin(), ans.end());
    ll mex2 = 0;
    vector<int> seen2(n + 1, 0);
    vector<ll> ans2;
    for (int i = 0; i < n; i++)
    {
        seen2[ans[i]]++;
        while (seen2[mex2])
            mex2++;
    }

    for (int i = 0; i < n; i++)
    {
        if (seen2[ans[i]] > 1)
        {
            ans2.push_back(mex2);
        }
        else
        {
            ans2.push_back(min(ans[i], mex2));
        }
    }
    sort(ans2.begin(), ans2.end());
    ll mex3 = 0;
    vector<int> seen3(n + 1, 0);
    vector<ll> ans3;
    for (int i = 0; i < n; i++)
    {
        seen3[ans2[i]]++;
        while (seen3[mex3])
            mex3++;
    }

    for (int i = 0; i < n; i++)
    {
        if (seen3[ans2[i]] > 1)
        {
            ans3.push_back(mex3);
        }
        else
        {
            ans3.push_back(min(ans2[i], mex3));
        }
    }
    ll sm1 = 0;
    ll sm2 = 0;
    ll sm3 = 0;
    for (auto c : ans)
    {
        sm1 += c;
    }
    for (auto c : ans2)
    {
        sm2 += c;
    }
    for (auto c : ans3)
    {
        sm3 += c;
    }
    if (k == 1)
    {
        cout << sm1 << "\n";
        return;
    }
    k--;
    if (k % 2 == 0)
    {
        cout << sm3 << "\n";
        return;
    }
    else
    {
        cout << sm2 << "\n";
        return;
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