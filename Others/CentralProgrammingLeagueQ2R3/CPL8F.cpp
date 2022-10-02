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

    int n, k, ai, mod = 14062008;
    cin >> n >> k;
    set<int> dd;
    for (int i = 0; i < k; i++) {
        cin >> ai;
        dd.insert(ai);
    }
    vector<int> f(n + 1, 0);
    f[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        if (dd.find(i) != dd.end())
            continue;
        f[i] = (f[i - 1] + f[i - 2]) % mod;
    }
    cout << f[n] << endl;

    return 0;
}
