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

// struct skill {
//     int type, dame;
//     skill();
//     skill(int t, int d): type(t), dame(d) {}
// };

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int t, n, di;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n), b1, b2;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> di;
            ans += di;
            if (a[i] == 0)
                b1.push_back(di);
            else
                b2.push_back(di);
        }
        sort(b1.begin(), b1.end());
        sort(b2.begin(), b2.end());
        while (b1.size() > 0 && b2.size() > 0) {
            if (b1.size() == 1 && b2.size() == 1) {
                ans += max(b1.back(), b2.back());
                break;
            }
            ans += b1.back();
            ans += b2.back();
            b1.pop_back();
            b2.pop_back();
        }
        cout << ans << endl;
        // vector<skill> ans;
        // if (b1.size() < b2.size())
        //     swap(b1, b2);
        // while (b1.size() > 0 || b2.size() > 0) {
        //     if (b1.size() > 0) {
        //         ans.push_back({0, b1.back()});
        //         b1.pop_back();
        //     }
        //     if (b2.size() > 0) {
        //         ans.push_back({1, b2.back()});
        //         b2.pop_back();
        //     }
        // }
        // reverse(ans.begin(), ans.end());
        // if (ans.size() > 2 && ans[0].type != ans[1].type && ans[0].dame > ans[1].dame) {
        //     for (int i = 0; i + 1 < n; i += 2)
        //         swap(ans[i], ans[i + 1]);
        // }
        // // for (int i = 0; i < n; i++)
        // //     cout << ans[i].type << '|' << ans[i].dame << ' ';
        // // cout << endl;
        // long long res = ans[0].dame;
        // for (int i = 1; i < n; i++) {
        //     res += ans[i].dame;
        //     if (ans[i].type != ans[i - 1].type)
        //         res += ans[i].dame;
        // }
        // cout << res << endl;
    }

    return 0;
}
