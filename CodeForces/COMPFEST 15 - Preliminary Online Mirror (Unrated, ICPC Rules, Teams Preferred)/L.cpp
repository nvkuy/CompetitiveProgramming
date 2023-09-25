#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)
#define low_bit(x) __builtin_ctzll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

long long over_come(long long j, long long y, long long k) {
    long long l = 0, r = 1e9 + 7, m;
    while (l < r) {
        m = (l + r) / 2;
        if (j + m < y + k * m)
            r = m;
        else
            l = m + 1;
    }
    return r;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, m;
    cin >> n >> m;
    
    long long ans = 0, k_ans = 1;
    for (long long k = 2; k <= m; k++) {
        vector<int> vis(k + 1, 0);
        long long tans = 0, cur_j = 1, cur_y = k;
        while (true) {
            if (cur_y > n) cur_y -= n;
            if (vis[cur_y] || cur_j == n) break;
            vis[cur_y] = 1;
            long long t1 = over_come(cur_j, cur_y, k);
            // cout << k << ' ' << cur_y << ' ' << cur_j << ' ' << t1 << endl;
            cur_j += t1;
            cur_y += t1 * k;
            if (cur_j > n) break;
            if (cur_y > n) continue;
            tans += cur_y;
            long long t2 = min((n - cur_y) / k, n - cur_j);
            tans += cur_y * t2 + k * (t2 * (t2 + 1)) / 2;
            cur_j += t2 + 1;
            cur_y += (t2 + 1) * k;
            // cout << k << ' ' << cur_y << endl;
        }
        if (ans < tans) {
            ans = tans;
            k_ans = k;
        }
    }

    cout << k_ans << endl;

    return 0;
}
