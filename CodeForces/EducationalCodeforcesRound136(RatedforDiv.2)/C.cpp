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

long long mod = 998244353;

long long bp(long long n, long long k) {
    if (k == 0)
        return 1;
    long long tmp;
    tmp = bp(n, k / 2);
    tmp = (tmp * tmp) % mod;
    if (k % 2)
        tmp = (tmp * n) % mod;
    return tmp;
}

long long iv(long long n) {
    return bp(n, mod - 2);
}

long long ckn(long long k, long long n) {
    if (k > n || min(k, n) < 0)
        return 0;
    long long t1 = 1, t2 = 1, t3 = 1;
    for (long long i = 1; i <= n; i++)
        t1 = (t1 * i) % mod;
    for (long long i = 1; i <= k; i++)
        t2 = (t2 * i) % mod;
    for (long long i = 1; i <= n - k; i++)
        t3 = (t3 * i) % mod;
    return (t1 * iv((t2 * t3) % mod)) % mod;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();
    
    int n, t;
    cin >> t;
    while (t--) {
        cin >> n;
        int ans = 0;
        for (int i = n; i > 0; i -= 4) {
            ans = (ans + ckn(i / 2, i - 1)) % mod;
            ans = (ans + ckn(i / 2 - 1, i - 4)) % mod;
        }
        int tans = (((ckn(n / 2, n) + mod - 1) % mod) + mod - ans) % mod;
        cout << ans << ' ' << tans << ' ' << 1 << endl;
    }

    return 0;
}
