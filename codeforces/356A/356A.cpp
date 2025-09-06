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
    vector<int> marked;
    SegTree(int n)
    {
        N = 1;
        while (N < n)
            N <<= 1;
        sg.resize(N << 1);
        marked.resize(N << 1);
        fill(sg.begin(), sg.end(), 0);
        fill(marked.begin(), marked.end(), 0);
    }

    void build(int v, int tl, int tr)
    {
        if (tl == tr)
        {
            sg[v] = 0;
        }
        else
        {
            int tm = (tl + tr) / 2;
            build(v << 1, tl, tm);
            build((v << 1) | 1, tm + 1, tr);
        }
    }

    void update(int v, int tl, int tr, int l, int r, int val)
    {
        if (l > r)
        {
            return;
        }
        if (tl == l && tr == r)
        {
            if (marked[v])
                return;
            sg[v] = val;
            marked[v] = 1;
        }
        else
        {
            push(v);
            int tm = (tl + tr) / 2;
            update(v << 1, tl, tm, l, min(r, tm), val);
            update((v << 1) | 1, tm + 1, tr, max(l, tm + 1), r, val);
        }
    }

    void push(int v)
    {
        if (marked[v])
        {
            if (!marked[v << 1])
            {
                marked[v << 1] = 1;
                sg[v << 1] = sg[v];
                marked[v] = 0;
            }
            if (!marked[(v << 1) | 1])
            {
                marked[(v << 1) | 1] = 1;
                sg[(v << 1) | 1] = sg[v];
                marked[v] = 0;
            }
        }
    }

    void updateOne(int v, int tl, int tr, int pos)
    {
        if (tl == tr)
        {
            sg[v] = 0;
            marked[v] = 0;
        }
        else
        {
            push(v);
            int tm = (tl + tr) / 2;
            if (pos <= tm)
            {
                updateOne(v << 1, tl, tm, pos);
            }
            else
            {
                updateOne((v << 1) | 1, tm + 1, tr, pos);
            }
        }
    }

    int fatherOf(int v, int tl, int tr, int pos)
    {
        if (tl == tr)
        {
            return sg[v];
        }
        else
        {
            push(v);
            int tm = (tl + tr) / 2;
            if (pos <= tm)
            {
                return fatherOf(v << 1, tl, tm, pos);
            }
            else
            {
                return fatherOf((v << 1) | 1, tm + 1, tr, pos);
            }
        }
    }

    int simple(int v) { return sg[v]; }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    SegTree sg(n);
    sg.build(1, 0, n - 1);
    while (m--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        l--;
        r--;
        sg.update(1, 0, n - 1, l, r, x);
        sg.updateOne(1, 0, n - 1, x - 1);
    }
    for (int i = 0; i < n; i++)
    {
        cout << sg.fatherOf(1, 0, n - 1, i) << " ";
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