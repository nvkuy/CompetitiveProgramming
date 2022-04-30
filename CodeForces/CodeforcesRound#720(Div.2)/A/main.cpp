#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    long long a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        long long y = b - 1, z = b + 1, x = 2;
        if (b == 1) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        cout << y * a << ' ' << z * a << ' ' << x * a * b << endl;
    }

    return 0;
}
