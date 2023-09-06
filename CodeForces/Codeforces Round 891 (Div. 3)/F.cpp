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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<long long, long long> cnt;
        while (n--) {
            long long x;
            cin >> x;
            cnt[x]++;
        }
        int q;
        cin >> q;
        while (q--) {
            long long x, y, t1, t2, t3, t4;
            set<pair<long long, long long>> sol;
            cin >> x >> y;
            t1 = x * x - 4 * y;
            t2 = sqrt(t1);
            if (t2 * t2 != t1) {
                cout << 0 << ' ';
                continue;
            }
            t1 = x + t2;
            if (t1 % 2 == 0) {
                t3 = t1 / 2;
                t4 = x - t3;
                if (t3 > t4) swap(t3, t4);
                sol.insert({t3, t4});
            }
            t1 = x - t2;
            if (t1 % 2 == 0) {
                t3 = t1 / 2;
                t4 = x - t3;
                if (t3 > t4) swap(t3, t4);
                sol.insert({t3, t4});
            }
            long long ans = 0;
            for (auto res : sol) {
                if (res.first == res.second)
                    ans += (cnt[res.first] * (cnt[res.first] - 1)) / 2;
                else
                    ans += cnt[res.first] * cnt[res.second];
            }
            cout << ans << ' ';
        }
        cout << endl;
    }

    return 0;
}
