#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define optimize()                \
    cin.tie(0);                   \
    cin.sync_with_stdio(0);       \
    ios_base::sync_with_stdio(0); \
    cout.tie(0);

struct SegTree
{
    int N;
    vector<int> sg;
    SegTree(int n)
    {
        N = 1;
        while (N < n)
            N <<= 1;
        sg.resize(N << 1);
    }

    void build(int v, int tl, int tr, vector<int> &a)
    {
        if (tl == tr)
        {
            sg[v] = a[tl];
        }
        else
        {
            int tm = (tr + tl) >> 1;
            build(v << 1, tl, tm, a);
            build(v << 1 | 1, tm + 1, tr, a);
            sg[v] = __gcd(sg[v << 1], sg[v << 1 | 1]);
        }
    }

    int query(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
        {
            return 0;
        }
        if (tl == l && tr == r)
        {
            return sg[v];
        }
        int tm = (tl + tr) >> 1;
        return __gcd(query(v << 1, tl, tm, l, min(r, tm)), query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r));
    }
};

struct MergeSegTree
{
    int N;
    vector<vector<int>> sg;
    MergeSegTree(int n)
    {
        N = 1;
        while (N < n)
            N <<= 1;
        sg.resize(N << 1);
    }

    void build(int v, int tl, int tr, vector<int> &a)
    {
        if (tl == tr)
        {
            sg[v] = vector<int>(1, a[tl]);
        }
        else
        {
            int tm = (tr + tl) >> 1;
            build(v << 1, tl, tm, a);
            build(v << 1 | 1, tm + 1, tr, a);
            merge(sg[v << 1].begin(), sg[v << 1].end(), sg[v << 1 | 1].begin(), sg[v << 1 | 1].end(), back_inserter(sg[v]));
        }
    }

    int query(int v, int tl, int tr, int l, int r, int val)
    {
        if (l > r)
        {
            return 0;
        }
        if (tl == l && tr == r)
        {
            int l = lower_bound(sg[v].begin(), sg[v].end(), val) - sg[v].begin();
            int r = upper_bound(sg[v].begin(), sg[v].end(), val) - sg[v].begin();
            return r - l;
        }
        int tm = (tr + tl) >> 1;
        return query(v << 1, tl, tm, l, min(r, tm), val) + query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, val);
    }

    vector<int> simple(int v)
    {
        return sg[v];
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &c : a)
        cin >> c;
    int t;
    cin >> t;
    SegTree gcdsg(n);
    gcdsg.build(1, 0, n - 1, a);
    MergeSegTree mgsg(n);
    mgsg.build(1, 0, n - 1, a);
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int gc = gcdsg.query(1, 0, n - 1, l, r);
        int ans = mgsg.query(1, 0, n - 1, l, r, gc);
        if (ans == 0)
            cout << r - l + 1 << "\n";
        else
            cout << (r - l + 1) - ans  << "\n";
    }
    return;
    for (int i = 1; i <= 1; i++)
    {
        vector<int> ps = mgsg.simple(i);
        int l = lower_bound(ps.begin(), ps.end(), 2) - ps.begin();
        int r = upper_bound(ps.begin(), ps.end(), 2) - ps.begin();
        cout << r - l << "\n";
    }
}

int main(void)
{
    optimize();
    int T;
    T = 1;
    while (T--)
        solve();
}