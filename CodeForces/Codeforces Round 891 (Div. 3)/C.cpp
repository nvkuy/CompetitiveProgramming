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
        vector<int> a(n * (n - 1) / 2);
        for (int i = 0; i < n * (n - 1) / 2; i++) cin >> a[i];
        sort(a.begin(), a.end());
        vector<int> ans;
        int cur = 0;
        for (int i = 1; i < n; i++) {
            ans.push_back(a[cur]);
            cur += n - i;
        }
        ans.push_back(ans.back());
        for (int num : ans) cout << num << ' ';
        cout << endl;
    }

    return 0;
}
