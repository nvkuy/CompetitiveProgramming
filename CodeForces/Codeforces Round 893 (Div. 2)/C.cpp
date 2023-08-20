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
        vector<int> ans, used(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            if (used[i]) continue;
            int num = i;
            while (true) {
                if (num > n) break;
                ans.push_back(num);
                used[num] = 1;
                num *= 2;
            }
        }
        for (int num : ans) cout << num << ' ';
        cout << endl;
    }

    return 0;
}
