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

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b) * b);
}

vector<long long> f(22, 0), a;
long long n, x;

void gen(int i, int cnt, long long l) {
    if (i == n) {
        f[cnt] += (x / l);
        return;
    }
    gen(i + 1, cnt, l);
    gen(i + 1, cnt + 1, lcm(l, a[i]));
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    long long ans = 0, tmp = 1;
    // vector<long long> f(22, 0);
    cin >> n >> x;
    // vector<long long> a(n);
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // for (int i = 1; i < (1 << n); i++) {
    //     bitset<22> bs(i);
    //     long long l = 1;
    //     for (int j = 0; j < n; j++)
    //         if (bs[j])
    //             l = lcm(l, a[j]);
    //     f[bs.count()] += (x / l);
    // }
    gen(0, 0, 1);
    for (int num = 1; num <= n; num++) {
        ans += (tmp * f[num]);
        tmp *= -1;
    }
    cout << ans << endl;

    return 0;
}
