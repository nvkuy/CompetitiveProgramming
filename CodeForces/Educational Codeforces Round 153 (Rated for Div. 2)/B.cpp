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

bool check(long long m, long long k, long long a1, long long ak, long long fancy) {
    long long t1 = ak * k;
    if (t1 >= m) m %= k;
    else m -= t1;
    long long t2 = fancy * k;
    if (t2 >= m) {
        long long tt = m / k;
        m %= k;
        fancy -= tt;
    } else {
        m -= t2;
        fancy = 0;
    }
    m -= a1;
    if (m > 0) fancy -= m;
    return fancy >= 0;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int m, k, a1, ak;
        cin >> m >> k >> a1 >> ak;
        int l = 0, r = m;
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(m, k, a1, ak, mid))
                r = mid;
            else
                l = mid + 1;
        }
        cout << r << endl;
    }

    return 0;
}
