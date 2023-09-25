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
        vector<long long> c(n + 1);
        for (int i = 1; i <= n; i++) cin >> c[i];
        long long k;
        cin >> k;
        vector<pair<long long, int>> real_pos;
        real_pos.push_back({c.back(), n});
        for (int i = n - 1; i > 0; i--) {
            if (c[i] >= real_pos.back().first) continue;
            real_pos.push_back({c[i], i});
        }
        reverse(real_pos.begin(), real_pos.end());
        vector<long long> ans(n + 1, 0), real_ans(n + 1, 0);
        long long remain = k % real_pos[0].first;
        ans[real_pos[0].second] = k / real_pos[0].first;
        for (int i = 1; i < real_pos.size(); i++) {
            long long diff = real_pos[i].first - real_pos[i - 1].first;
            long long change = min(ans[real_pos[i - 1].second], remain / diff);
            ans[real_pos[i - 1].second] -= change;
            ans[real_pos[i].second] += change;
            remain -= diff * change;
        }
        long long cur_seg = 0;
        for (int i = n; i > 0; i--) {
            cur_seg += ans[i];
            real_ans[i] += cur_seg;
        }
        for (int i = 1; i <= n; i++)
            cout << real_ans[i] << ' ';
        cout << endl;
    }

    return 0;
}
