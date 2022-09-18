#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

bool try_make(long long n, long long m, vector<int> a) {
    bool hasMore = false;
    for (int i = 0; i < a.size(); i++) {
        if ((a[i] / n) < 2)
            continue;
        int rd = a[i] / n;
        if (rd > 2)
            hasMore = true;
        m -= rd;
    }
    if (m > 0)
        return false;
    m = -m;
    if (m % 2 == 1)
        return hasMore;
    return true;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, m, k;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        vector<int> a(k);
        for (int i = 0; i < k; i++)
            cin >> a[i];
        bool ans = (try_make(n, m, a) | try_make(m, n, a));
        cout << (ans ? "YES" : "NO") << endl;
    }

    return 0;
}