#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, k;
    cin >> n;
    for (long long k = 1; k <= n; k++)
        cout << (((k * k) * (k * k - 1)) / 2LL) - 4LL * max(k - 2, 0LL) * (k - 1LL) << endl;

    return 0;
}
