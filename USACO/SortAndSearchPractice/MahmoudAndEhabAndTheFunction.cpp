#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal()
{
    if (!fopen("input.txt", "r"))
        return;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

long long cal(long long cur_sum_a, set<long long> &sum_b)
{
    auto it = sum_b.lower_bound(cur_sum_a);
    if (it == sum_b.end())
        it--;
    long long ans = abs(cur_sum_a - (*it));
    if (it != sum_b.begin())
    {
        it--;
        ans = min(ans, abs(cur_sum_a - (*it)));
    }
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    debugLocal();

    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    long long cur_sum_a = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2)
            cur_sum_a -= a[i];
        else
            cur_sum_a += a[i];
    }
    long long cur_sum_b = 0;
    set<long long> sum_b;
    for (int i = 0; i < m; i++)
    {
        if (i - n >= 0)
        {
            int j = i - n;
            cur_sum_b -= b[j];
            cur_sum_b = -cur_sum_b;
        }
        if (((i < n) && (i % 2)) || ((i >= n) && ((n - 1) % 2)))
            cur_sum_b -= b[i];
        else
            cur_sum_b += b[i];
        if (i - n + 1 >= 0)
            sum_b.insert(cur_sum_b);
    }

    cout << cal(cur_sum_a, sum_b) << endl;
    while (q--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        if ((r - l + 1) % 2)
        {
            if (l % 2)
                cur_sum_a += x;
            else
                cur_sum_a -= x;
        }
        cout << cal(cur_sum_a, sum_b) << endl;
    }

    return 0;
}
