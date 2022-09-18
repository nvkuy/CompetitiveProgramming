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

    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        if (n > m || (n % 2 == 0 && m % 2 == 1)) {
            cout << "No" << endl;
            continue;
        }
        vector<int> ans;
        int num1 = (n / 2) * 2;
        if (num1 == n && num1 < m)
            num1 -= 2;
        for (int i = 0; i < num1; i++) {
            ans.push_back(1);
            m--;
        }
        if (num1 + 1 == n)
            ans.push_back(m);
        else {
            ans.push_back(m / 2);
            ans.push_back(m / 2);
        }
        cout << "Yes" << endl;
        for (int i = 0; i < n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }

    return 0;
}
