#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, ans = 1LL, mod = 1e9 + 7;
    cin >> n;
    while (n--)
        ans = ((ans * 2LL) % mod);
    cout << ans;

    return 0;
}
