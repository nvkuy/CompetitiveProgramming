#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

long long modExpo(long long x, long long n, long long M)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
        return modExpo((x * x) % M, n / 2, M);
    else
        return (x * modExpo((x * x) % M, (n - 1) / 2, M)) % M;
}

long long modInvFE(int A, int M)
{
    return modExpo(A, M - 2, M);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, mod = 2027, ans = 0;
    cin >> n;
    ans += ((n % mod) * (n % mod) * ((n - 1) % mod)) % mod;
    ans += ((n % mod) * ((n + 1) % mod)) % mod;
    ans %= mod;
    ans *= modInvFE(2, mod);
    ans %= mod;
    cout << ans << endl;

    return 0;
}
