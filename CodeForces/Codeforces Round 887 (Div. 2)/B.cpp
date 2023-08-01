#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

bool iok(int n, int k, int pre_n) {
    int n1 = n, n2 = pre_n;
    for (int i = 0; i < k - 2; i++) {
        int t1 = n1 - n2;
        n1 = n2;
        n2 = t1;
        if (n2 > n1)
            return false;
        if (n2 < 0)
            return false;
    }
    return true;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k, ans = 0;
        cin >> n >> k;
        for (int i = 0; i <= n; i++)
            ans += iok(n, k, i);
        cout << ans << endl;
    }

    return 0;
}
