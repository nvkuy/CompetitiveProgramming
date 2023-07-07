#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal() {
    if (!fopen("input.txt", "r"))
        return;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int cal(int remain, int pos, vector<long long> &ps, vector<pair<int, int>> segs) {
    if (ps[segs.size()] - ps[pos] < remain) return 2e9 + 14;
    int l = pos + 1, r = segs.size();
    while (l < r) {
        int m = (l + r) / 2;
        if (ps[m] - ps[pos] >= remain)
            r = m;
        else
            l = m + 1;
    }
    int ans = 2 * (r - pos);
    ans += segs[r].first - segs[pos].first;
    remain -= (ps[r - 1] - ps[pos]);
    ans += (remain - 1);
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> ls(n), rs(n);
        for (int i = 0; i < n; i++) cin >> ls[i];
        for (int i = 0; i < n; i++) cin >> rs[i];
        vector<pair<int, int>> segs;
        for (int i = 0; i < n; i++)
            segs.push_back({ls[i], rs[i]});
        sort(segs.begin(), segs.end());
        vector<pair<int, int>> real_segs;
        int cur_l = segs[0].first, cur_r = segs[0].second;
        for (int i = 0; i < n; i++) {
            if (segs[i].first <= cur_r + 1) cur_r = max(cur_r, segs[i].second);
            if (segs[i].first > cur_r + 1) {
                real_segs.push_back({cur_l, cur_r});
                cur_l = segs[i].first;
                cur_r = segs[i].second;
            }
            if (i + 1 == n) real_segs.push_back({cur_l, cur_r});
        }
        vector<long long> ps(1, 0);
        for (auto seg : real_segs)
            ps.push_back(ps.back() + (seg.second - seg.first + 1));
        int ans = 2e9 + 14, cur_pos = 0, op = 0;
        for (int i = 0; i + 1 < real_segs.size(); i++) {
            // op += segs[i].first - cur_pos;
            // cur_pos
        }
        if (ans > 2e9)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }

    return 0;
}
