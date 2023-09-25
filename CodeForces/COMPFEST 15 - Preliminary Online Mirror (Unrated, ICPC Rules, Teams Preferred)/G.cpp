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
    vector<int> a(n), d(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> d[i];
    
    vector<vector<pair<int, int>>> segs(n);
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) continue;
        int l = max(0, i - d[i]);
        segs[l].push_back({i + d[i], a[i]});
    }

    int l = 0, r = 1e9 + 7, m;
    while (l < r) {
        m = (l + r) / 2;
        multiset<pair<int, int>> inside;
        for (int i = 0; i < n; i++) {
            if (inside.size() > 0 && inside.begin()->first < i) break;
            for (auto seg : segs[i])
                inside.insert(seg);
            int rm = m;
            while (true) {
                if (rm == 0 || inside.size() == 0) break;
                auto seg = *inside.begin();
                inside.erase(inside.begin());
                int move = min(rm, seg.second);
                rm -= move;
                seg.second -= move;
                if (seg.second > 0)
                    inside.insert(seg);
            }
        }
        if (inside.size() == 0)
            r = m;
        else
            l = m + 1;
    }

    cout << r << endl;

    return 0;
}
