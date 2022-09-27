#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("in.txt", "r", stdin);

    while (true) {
        vector<int> a(5);
        for (int i = 0; i < 5; i++)
            cin >> a[i];
        if ((a[0] + a[1] + a[2] + a[3] + a[4]) == 0)
            break;
        int ans = -1;
        for (int i = 1; i <= 52; i++) {
            if (i == a[0] || i == a[1] || i == a[2] || i == a[3] || i == a[4])
                continue;
            vector<int> v1, v2;
            v1 = {a[0], a[1], a[2]};
            v2 = {a[3], a[4], i};
            sort(v1.begin(), v1.end());
            sort(v2.begin(), v2.end());
            if (v1[1] > v2[0] && v1[2] > v2[1])
                continue;
            ans = i;
            break;
        }
        cout << ans << endl;
    }

    return 0;
}