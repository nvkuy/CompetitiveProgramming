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
        vector<pair<int, int>> a(n);
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int ai;
            cin >> ai;
            a[i] = {ai, i};
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++)
            ans[a[i].second] = n - i;
        for (int num : ans) cout << num << ' ';
        cout << endl;
    }

    return 0;
}
