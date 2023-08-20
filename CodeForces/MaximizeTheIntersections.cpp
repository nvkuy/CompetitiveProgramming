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

bool inside(int l, int r, int p) {
    return p >= l && p <= r;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> used(2 * n, 0), free;
        vector<pair<int, int>> range;
        while (k--) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            used[x] = used[y] = 1;
            if (x > y) swap(x, y);
            range.push_back({x, y});
        }
        for (int i = 0; i < 2 * n; i++)
            if (!used[i]) free.push_back(i);
        for (int i = free.size() / 2; i < free.size(); i++)
            range.push_back({free[i - free.size() / 2], free[i]});
        int ans = 0;
        for (auto r1 : range) {
            for (auto r2 : range) {
                ans += ((inside(r1.first, r1.second, r2.first) && !inside(r1.first, r1.second, r2.second)) || (!inside(r1.first, r1.second, r2.first) && inside(r1.first, r1.second, r2.second)));
            }
        }
        cout << ans / 2 << endl;
    }

    return 0;
}
