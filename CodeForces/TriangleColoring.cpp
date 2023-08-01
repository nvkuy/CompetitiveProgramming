#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

long long const mod = 998244353;
long long power(long long num, long long pow) {
    if (pow == 0) return 1;
    if (pow % 2) return (num * power(num, pow - 1)) % mod;
    return power((num * num) % mod, pow / 2);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    long long ways = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i % 3 == 2) {
            sort(a.begin() + i - 2, a.begin() + i + 1);
            if (a[i] == a[i - 2])
                ways = (ways * 3) % mod;
            else if (a[i - 1] == a[i - 2])
                ways = (ways * 2) % mod;
        }
    }
    long long t1 = 1, t2 = 1;
    for (long long i = 1; i <= n / 3; i++) {
        t1 = (t1 * i) % mod;
        if (i <= n / 6)
            t2 = (t2 * i) % mod;
    }

    // cout << ways << endl;
    // cout << ((t1 * power((t2 * t2) % mod, mod - 2)) % mod) << endl;
    cout << (ways * ((t1 * power((t2 * t2) % mod, mod - 2)) % mod)) % mod << endl;

    return 0;
}
