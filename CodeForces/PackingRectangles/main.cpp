#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long w, h, n;
    cin >> w >> h >> n;

    long long l = 1, r = 1e18, m;
    while (l < r) {
        m = (l + r) / 2LL;
        long long t1 = m / w, t2 = m / h;
        if ((min(t1, t2) > 0 && max(t1, t2) > 1e9) || (t1 * t2 >= n))
            r = m;
        else
            l = m + 1;
        //cout << l << '|' << r << endl;
    }
    cout << l;

    return 0;
}
