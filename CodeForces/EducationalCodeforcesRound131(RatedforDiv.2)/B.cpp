#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugMode() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugMode();

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> dd(n + 1, 0), ans;
        for (int i = 1; i <= n; i++) {
            int tmp = i;
            while (tmp <= n && dd[tmp] == 0) {
                ans.push_back(tmp);
                dd[tmp] = 1;
                tmp *= 2;
            }
        }
        for (int i = 1; i <= n; i++)
            if (dd[i] == 0) ans.push_back(i);
        cout << 2 << endl;
        for (int a : ans)
            cout << a << ' ';
        cout << endl;
    }

    return 0;
}
