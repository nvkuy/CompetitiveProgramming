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

int cal(int num) {
    string tmp = to_string(num);
    sort(tmp.begin(), tmp.end());
    return abs((tmp[0] - '0') - (tmp.back() - '0'));
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        int ans = l, num = cal(l);
        for (int i = l; i <= min(l + 101, r); i++) {
            if (num < cal(i)) {
                ans = i;
                num = cal(i);
            }
        }
        for (int i = r; i >= max(r - 101, l); i--) {
            if (num < cal(i)) {
                ans = i;
                num = cal(i);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
