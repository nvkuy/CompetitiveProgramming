#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, ans = 1;
    cin >> n;
    vector<int> pos1(n + 2, 0), pos2(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        int ai;
        cin >> ai;
        pos1[ai] = i;
    }
    for (int i = 1; i <= n; i++) {
        int ai;
        cin >> ai;
        pos2[ai] = i;
    }

    long long t1, t2, t3;
    pair<int, int> pre_range = {1e9, -1e9};
    pre_range.first = min(pre_range.first, pos1[1]);
    pre_range.first = min(pre_range.first, pos2[1]);
    pre_range.second = max(pre_range.second, pos1[1]);
    pre_range.second = max(pre_range.second, pos2[1]);
    t1 = pre_range.first - 1, t2 = n - pre_range.second, t3 = pre_range.second - pre_range.first - 1;
    ans += (t1 * (t1 + 1)) / 2;
    ans += (t2 * (t2 + 1)) / 2;
    ans += (t3 * (t3 + 1)) / 2;
    // cout << "@st: " << t1 << ' ' << t2 << ' ' << t3 << endl;
    int mex1 = 1, mex2 = 1, mex = 2;
    while (true) {
        if (mex > n) break;
        while (pos1[mex1] >= pre_range.first && pos1[mex1] <= pre_range.second) mex1++;
        while (pos2[mex2] >= pre_range.first && pos2[mex2] <= pre_range.second) mex2++;
        if (mex1 == mex2) {
            if (mex1 > mex) {
                mex++;
                continue;
            }
            pair<int, int> allow_range = {1, n};
            if (max(pos1[mex], pos2[mex]) < pre_range.first)
                allow_range.first = max(pos1[mex], pos2[mex]) + 1;
            else if (min(pos1[mex], pos2[mex]) > pre_range.second)
                allow_range.second = min(pos1[mex], pos2[mex]) - 1;
            else
                allow_range = {min(pos1[mex], pos2[mex]) + 1, max(pos1[mex], pos2[mex]) - 1};
            // cout << "@mex: " << mex << ' ' << pre_range.first << ' ' << pre_range.second << ' ' << allow_range.first << ' ' << allow_range.second << endl;
            t1 = pre_range.first - allow_range.first + 1, t2 = allow_range.second - pre_range.second + 1;
            ans += (t1 * t2);
            pre_range.first = min(pre_range.first, pos1[mex]);
            pre_range.first = min(pre_range.first, pos2[mex]);
            pre_range.second = max(pre_range.second, pos1[mex]);
            pre_range.second = max(pre_range.second, pos2[mex]);
            continue;
        }
        while (mex1 < mex2) {
            pre_range.first = min(pre_range.first, pos1[mex1]);
            pre_range.second = max(pre_range.second, pos1[mex1]);
            mex1++;
        }
        while (mex1 > mex2) {
            pre_range.first = min(pre_range.first, pos2[mex2]);
            pre_range.second = max(pre_range.second, pos2[mex2]);
            mex2++;
        }
    }

    cout << ans << endl;

    return 0;
}
