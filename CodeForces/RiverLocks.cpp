#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<long long> a(n + 1, 0), ps(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ps[i] = ps[i - 1] + a[i];
    }

    vector<pair<long long, long long>> f1(n + 1, {0, 0});
    vector<long long> f2(n + 1, 1e9);

    for (long long i = 1; i <= n; i++) {
        long long cur_vol = f1[i - 1].first, pre_rm = f1[i - 1].second;
        if (cur_vol + pre_rm >= a[i]) {
            f1[i] = {cur_vol, pre_rm + cur_vol - a[i]};
            continue;
        }
        long long cur_rm = a[i] - cur_vol - pre_rm;
        long long need_time = cur_rm / i;
        if (need_time * i < cur_rm) need_time++;
        f1[i] = {cur_vol + need_time, need_time * i - cur_rm};
    }

    for (long long i = 1; i <= n; i++) {
        long long rm = ps[n] - ps[i];
        rm -= f1[i].second;
        if (rm <= 0) {
            f2[i] = f1[i].first;
            continue;
        }
        long long need_time = rm / i;
        if (need_time * i < rm) need_time++;
        f2[i] = f1[i].first + need_time;
    }

    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (f2[n] > t) {
            cout << -1 << endl;
            continue;
        }
        int l = 1, r = n, m;
        while (l < r) {
            m = (l + r) / 2;
            if (f2[m] <= t)
                r = m;
            else
                l = m + 1;
        }
        cout << r << endl;
    }

    return 0;
}
