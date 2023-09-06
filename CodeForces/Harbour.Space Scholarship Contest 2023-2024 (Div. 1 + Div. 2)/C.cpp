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
        int x;
        cin >> x;
        vector<int> ans;
        ans.push_back(x);
        while (true) {
            if (bit_cnt(x) == 1) break;
            int tmp = 0;
            for (int i = 0; i < 30; i++)
                if (((1 << i) & x)) {
                    tmp = i;
                    break;
                }
            x -= (1 << tmp);
            ans.push_back(x);
        }
        while (true) {
            if (x == 1) break;
            x /= 2;
            ans.push_back(x);
        }
        cout << ans.size() << endl;
        for (int num : ans) cout << num << ' ';
        cout << endl;
    }

    return 0;
}
