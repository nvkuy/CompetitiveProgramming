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
        vector<int> a;
        string ans;
        bool isSorted = true;
        while (q--) {
            int xi;
            cin >> xi;
            if (isSorted) {
                if (a.size() == 0 || a.back() <= xi) {
                    a.push_back(xi);
                    ans.push_back('1');
                    continue;
                }
                if (a[0] >= xi) {
                    a.push_back(xi);
                    isSorted = false;
                    ans.push_back('1');
                } else
                    ans.push_back('0');
            } else {
                if (a.back() > xi) {
                    ans.push_back('0');
                    continue;
                }
                if (a[0] < xi)
                    ans.push_back('0');
                else {
                    ans.push_back('1');
                    a.push_back(xi);
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
