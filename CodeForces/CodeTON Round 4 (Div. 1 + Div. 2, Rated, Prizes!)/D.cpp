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
        int q;
        cin >> q;
        vector<long long> ans;
        pair<long long, long long> curRange = {-1, -1};
        while (q--) {
            int type;
            cin >> type;
            if (type == 1) {
                long long a, b, n;
                cin >> a >> b >> n;
                long long dis = (n - 1LL) * (a - b);
                if (curRange.first < 0) {
                    ans.push_back(1);
                    if (n > 1)
                        curRange = {dis + b, dis + a};
                    else
                        curRange = {0, a};
                    continue;
                }
                long long lx = dis + b, rx = dis + a;
                if (n == 1) lx = 0;
                if (lx >= curRange.second || rx <= curRange.first) {
                    ans.push_back(0);
                    continue;
                }
                curRange.first = max(curRange.first, lx);
                curRange.second = min(curRange.second, rx);
                ans.push_back(1);
            } else {
                long long a, b;
                cin >> a >> b;
                if (curRange.first < 0) {
                    ans.push_back(-1);
                    continue;
                }
                long long tmp1 = max(curRange.second - a, 0LL);
                long long tmp2 = tmp1 / (a - b);
                if (tmp2 * (a - b) + a < curRange.second)
                    tmp2++;
                if (tmp2 > 0 && (tmp2 - 1LL) * (a - b) + a > curRange.first) {
                    ans.push_back(-1);
                    continue;
                }
                ans.push_back(tmp2 + 1);
            }
        }
        for (long long ai : ans)
            cout << ai << ' ';
        cout << endl;
    }

    return 0;
}
