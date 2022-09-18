#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, a, b, c, x, y;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> x >> y;
        if (a < x)
            c -= (x - a);
        if (b < y)
            c -= (y - b);
        cout << ((c >= 0) ? "YES" : "NO") << endl;
    }

    return 0;
}
