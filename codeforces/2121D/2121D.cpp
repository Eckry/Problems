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
    vector<int> b(n);
    for (auto &c : a)
        cin >> c;
    for (auto &c : b)
        cin >> c;

    int op = 0;
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0 && b[i] & 1)
        {
            op++;
            int temp = a[i];
            a[i] = b[i];
            b[i] = temp;
            ans.push_back({3, i});
        }
    }
    for (int k = 0; k < n; k++)
    {

        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 == 0)
            {
                int left = i;
                int right = i;
                int distanceleft = 10000;
                int distanceright = 10000;
                while (left >= 0 && b[left] % 2 == 0)
                    left--;
                while (right < n && b[right] % 2 == 0)
                    right++;
                if (left != -1)
                    distanceleft = i - left;
                if (right != n)
                    distanceright = right - i;

                if (distanceright < distanceleft)
                {
                    for (int j = i; j < right; j++)
                    {
                        op++;
                        ans.push_back({1, j});
                        int temp = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = temp;
                    }
                    ans.push_back({3, right});
                    op++;
                    int temp = a[right];
                    a[right] = b[right];
                    b[right] = temp;
                }
                else
                {
                    for (int j = i; j > left; j--)
                    {
                        ans.push_back({1, j - 1});
                        int temp = a[j];
                        a[j] = a[j - 1];
                        a[j - 1] = temp;
                        op++;
                    }
                    ans.push_back({3, left});
                    op++;
                    int temp = a[left];
                    a[left] = b[left];
                    b[left] = temp;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j + 1] < a[j])
            {
                ans.push_back({1, j});
                int temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
                op++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (b[j + 1] < b[j])
            {
                ans.push_back({2, j});
                int temp = b[j + 1];
                b[j + 1] = b[j];
                b[j] = temp;
                op++;
            }
        }
    }
    cout << op << " \n";
    for (auto c : ans)
    {
        cout << c[0] << " " << c[1] + 1 << "\n";
    }

    // for (auto c : a)
    // {
    //     cout << c << " ";
    // }
    // cout << " \n";
    // for (auto c : b)
    // {
    //     cout << c << " ";
    // }
    // cout << " \n";
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