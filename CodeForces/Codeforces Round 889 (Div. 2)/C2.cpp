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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1, 0);
        int pos_idx = 0, neg_idx = 0, neg_cnt = 0, pos_cnt = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] < 0) {
                neg_cnt++;
                if (neg_idx == -1 || a[i] < a[neg_idx])
                    neg_idx = i;
            }
            if (a[i] > 0) {
                pos_cnt++;
                if (pos_idx == -1 || a[i] > a[pos_idx])
                    pos_idx = i;
            }
        }
        if (max(pos_cnt, neg_cnt) == 0) {
            cout << 0 << endl;
            continue;
        }
        bool goNeg = true;
        vector<pair<int, int>> ops;
        if (abs(a[neg_idx]) == abs(a[pos_idx])) {
            if (pos_cnt >= neg_cnt) {
                goNeg = false;
                for (int i = 1; i <= n; i++)
                    if (a[i] < 0) ops.push_back({i, pos_idx});
            } else {
                for (int i = 1; i <= n; i++)
                    if (a[i] > 0) ops.push_back({i, neg_idx});
            }
        } else if (abs(a[neg_idx]) > abs(a[pos_idx])) {
            if (pos_cnt <= 12) {
                for (int i = 1; i <= n; i++)
                    if (a[i] > 0) ops.push_back({i, neg_idx});
            } else {
                goNeg = false;
                for (int i = 0; i < 5; i++)
                    ops.push_back({pos_idx, pos_idx});
                for (int i = 1; i <= n; i++)
                    if (a[i] < 0) ops.push_back({i, pos_idx});
            }
        } else {
            if (neg_cnt <= 12) {
                goNeg = false;
                for (int i = 1; i <= n; i++)
                    if (a[i] < 0) ops.push_back({i, pos_idx});
            } else {
                for (int i = 0; i < 5; i++)
                    ops.push_back({neg_idx, neg_idx});
                for (int i = 1; i <= n; i++)
                    if (a[i] > 0) ops.push_back({i, neg_idx});
            }
        }
        if (goNeg) {
            for (int i = n - 1; i >= 1; i--)
                ops.push_back({i, i + 1});
        } else {
            for (int i = 2; i <= n; i++)
                ops.push_back({i, i - 1});
        }
        cout << ops.size() << endl;
        for (auto p : ops) cout << p.first << ' ' << p.second << endl;
    }

    return 0;
}
