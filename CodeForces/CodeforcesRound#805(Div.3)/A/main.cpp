#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long t, m;
    cin >> t;
    while (t--) {
        cin >> m;
        long long p10 = 1;
        while (p10 * 10LL <= m)
            p10 *= 10LL;
        cout << m - p10 << endl;
    }

    return 0;
}
