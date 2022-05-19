#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long t, a, b, c;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        long long z = c, y = b, x = (long long)(1e9) * b + a;
        cout << x << ' ' << y << ' ' << z << endl;
    }

    return 0;
}
