#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, x, y;
    cin >> n >> x >> y;
    long long l = 0, r = 1e14, m;
    while (l < r) {
        m = (l + r) / 2;
        long long nc = 0;
        nc += (m / min(x, y));
        if (m >= min(x, y))
            nc += ((m - min(x, y)) / max(x, y));
        if (nc >= n)
            r = m;
        else
            l = m + 1;
    }
    cout << l;

    return 0;
}
