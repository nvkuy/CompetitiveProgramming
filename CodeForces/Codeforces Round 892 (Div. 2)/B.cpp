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
        vector<vector<int>> a(n);
        vector<int> second_min;
        int real_min = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            int m;
            cin >> m;
            a[i].resize(m);
            for (int j = 0; j < m; j++) cin >> a[i][j];
            sort(a[i].begin(), a[i].end(), greater<int>());
            real_min = min(real_min, a[i].back());
            a[i].pop_back();
            second_min.push_back(a[i].back());
        }
        sort(second_min.begin(), second_min.end(), greater<int>());
        second_min.pop_back();
        second_min.push_back(real_min);
        long long ans = 0;
        for (int num : second_min) ans += num;
        cout << ans << endl;
    }

    return 0;
}
