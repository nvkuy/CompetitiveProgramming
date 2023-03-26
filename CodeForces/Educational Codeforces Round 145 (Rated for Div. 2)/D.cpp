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
        string s;
        cin >> s;
        int n = s.length();
        s = "0" + s;
        vector<long long> f(n + 1,  0);
        long long cost = 2e18, costDel = 1e12 + 1;
        for (int i = 1; i <= n; i++) f[i] = f[i - 1] + (s[i] - '0');
        for (int i = n; i > 0; i--) {
            long long prefOneCnt = f[i - 1], suffOneCnt = f[n] - prefOneCnt, suffZeroCnt = n - i + 1 - suffOneCnt;
            long long suffCost = suffZeroCnt * costDel;
            // cout << i << '|' << prefOneCnt << '|' << suffOneCnt << endl;
            if (i + 1 <= n && s[i + 1] == '0' && s[i] == '1') suffCost--;
            if (s[i] == '0') suffCost -= costDel;
            cost = min(cost, costDel * prefOneCnt + suffCost);
        }
        cout << cost << endl;
    }

    return 0;
}
