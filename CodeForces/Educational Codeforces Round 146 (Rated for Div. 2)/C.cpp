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

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int t;
    cin >> t;
    while (t--) {
        int n, s1, s2;
        cin >> n >> s1 >> s2;
        vector<pair<int, int>> rp;
        for (int i = 0; i < n; i++) {
            int r;
            cin >> r;
            rp.push_back({r, i + 1});
        }
        sort(rp.begin(), rp.end(), greater<pair<int, int>>());
        int t1 = 0, t2 = 0;
        vector<int> ans1, ans2;
        for (auto p : rp) {
            if (t1 + s1 < t2 + s2) {
                ans1.push_back(p.second);
                t1 += s1;
            } else {
                ans2.push_back(p.second);
                t2 += s2;
            }
        }
        cout << ans1.size() << ' ';
        for (int p : ans1) cout << p << ' ';
        cout << endl;
        cout << ans2.size() << ' ';
        for (int p : ans2) cout << p << ' ';
        cout << endl;
    }

    return 0;
}
