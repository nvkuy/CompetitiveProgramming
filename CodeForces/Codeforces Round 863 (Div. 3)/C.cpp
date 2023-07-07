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
        int n;
        cin >> n;
        vector<int> a(n - 1);
        for (int i = 0; i + 1 < n; i++) cin >> a[i];
        // int min_pos = 0;
        // for (int i = 0; i + 1 < n; i++) {
        //     if (a[min_pos] > a[i])
        //         min_pos = i;
        // }
        // for (int i = 0; i <= min_pos; i++) cout << a[i] << ' ';
        // for (int i = min_pos; i + 1 < n; i++) cout << a[i] << ' ';
        // cout << endl;
        vector<int> ans;
        for (int i = 0; i + 1 < n; i++) {
            bool lowL = i - 1 < 0;
            if (i - 1 >= 0 && a[i - 1] > a[i])
                lowL = true;
            bool lowR = i + 2 > n;
            if (i + 2 < n && a[i + 1] > a[i])
                lowR = true;
            ans.push_back(a[i]);
            if (lowL && lowR)
                ans.push_back(a[i]);
        }
        for (int ai : ans) cout << ai << ' ';
        cout << endl;
    }

    return 0;
}
